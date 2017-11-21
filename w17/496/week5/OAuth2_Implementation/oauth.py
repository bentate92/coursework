############################################################################################
# Name: Benjamin Tate
# Date: 2/12/2017
# Class: CS 496, Section 400
# Assignment: OAuth 2.0 Implementation
# Description: Implementation of basic OAuth 2.0 server side flow
############################################################################################

from google.appengine.ext import ndb
from google.appengine.api import urlfetch
from google.appengine.api import memcache
import urllib
import string
import random
import logging
import webapp2
import json

#Constant string variables
client_id = '1040498597336-nm2aktqifbkevddlpk59ppic6nd4ic9f.apps.googleusercontent.com'
client_secret = 'UvdGnVKYCvcnE5Bpxoux2SoO'
redirect = 'https://oauth-158423.appspot.com/oauth'

#Function to create a random state string
def genstate(n):
    chars = string.ascii_uppercase + string.ascii_lowercase + string.digits
    return ''.join(random.choice(chars) for _ in range(n))

#Handles requests to the main page
class MainPage(webapp2.RequestHandler):
    #GET function to send first request google
    def get(self):
        #Create random state string
        state = genstate(10)
        #Save state string using memcache
        memcache.set(key='state', value=state, time=3600)
        #Redirect to google with appropriate headers
        self.redirect('https://accounts.google.com/o/oauth2/v2/auth?response_type=code&client_id=' + client_id +'&redirect_uri=' + redirect + '&scope=email&state=' + state)

#Handles requests to the /oauth page
class OauthHandler(webapp2.RequestHandler):
    #GET function to continue flow 
    def get(self):
        #Set code and state from request contents
        code = self.request.get('code')
        state = self.request.get('state')

        #Log code and state
        logging.debug('code = ' + code)
        logging.debug('state = ' + memcache.get(key='state') + ' & returned_state = ' + state)

        #If the states match...
        if state == memcache.get(key='state'):
            #Sending POST request to google's servers
            try:
                #Set request header
                headers = {'Content-Type': 'application/x-www-form-urlencoded'}
                #Set request body
                data = {
                    'code': code,
                    'client_id': client_id,
                    'client_secret': client_secret,
                    'redirect_uri': redirect,
                    'grant_type': 'authorization_code'
                }

                #Send POST request to google using urlfetch
                result = urlfetch.fetch(
                    url='https://www.googleapis.com/oauth2/v4/token',
                    payload=urllib.urlencode(data),
                    method=urlfetch.POST,
                    headers=headers)

                #Load result.content into token_response and retrieve access_token
                token_response = json.loads(result.content)
                #Log access_token
                logging.debug('access_token = ' + token_response['access_token'])
                access_token = token_response['access_token']

                #Sending GET request to google's servers
                try:
                    #Set request header using access_token
                    headers = {'Authorization': 'Bearer ' + access_token}

                    #Send GET request to google using urlfetch
                    result = urlfetch.fetch(
                            url='https://www.googleapis.com/plus/v1/people/me',
                            method=urlfetch.GET,
                            headers=headers)

                    #Check success
                    if result.status_code == 200:
                        #Load result.content into info_response
                        info_response = json.loads(result.content)
                        #Retrieve info from info_response
                        name = info_response['name']
                        fname = name['givenName']
                        lname = name['familyName']
                        gplus = info_response['url']

                        #Make hyperlink
                        glink = '<a href="' + gplus + '">' + gplus + '<a/>'

                        #Log info
                        logging.debug('First Name: ' + fname)
                        logging.debug('Last Name: ' + lname)
                        logging.debug('Google+ URL: ' + gplus)
                        logging.debug('State Variable: ' + state)
                        
                        #Write first name, last name, google+ url, and state string
                        self.response.write('First Name: ' + fname + '<br/>')
                        self.response.write('Last Name: ' + lname + '<br/>')
                        self.response.write('Google+: ' + glink + '<br/>')
                        self.response.write('State Variable: ' + state)
                    else:
                        #Set status code if not 200
                        self.response.status_int = result.status_code
                except urlfetch.Error:
                    #Throw error if GET fetch failed
                    logging.exception('ERROR (GET): Caught exception fetching url')
            except urlfetch.Error:
                #Throw error if POST fetch failed
                logging.exception('ERROR (POST): Caught exception fetching url')
        else:
            #Throw error if state strings don't match
            self.response.write('ERROR: The super secret codes do not match!')
            self.response.status_int = 403

app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/oauth', OauthHandler)
], debug = True)
