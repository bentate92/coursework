############################################################################################
# Name: Benjamin Tate
# Date: 2/5/2017
# Class: CS 496, Section 400
# Assignment: REST Implementation
# Description: Implementation of a simple, RESTful library API
# Note: Apologies if there is weird indentation in this file. I wrote this using Sublime 
#		Text, but apparently it looks very weird in vim due to some tab/space discrepancies.
############################################################################################

from google.appengine.ext import ndb
import webapp2
import json

#Defines Book object
class Book(ndb.Model):
	id = ndb.StringProperty()
	title = ndb.StringProperty()
	isbn = ndb.StringProperty()
	author = ndb.StringProperty()
	genre = ndb.StringProperty(repeated=True)
	checkedIn = ndb.BooleanProperty(required=True)

#Defines Customer object
class Customer(ndb.Model):
	id = ndb.StringProperty()
	name = ndb.StringProperty()
	balance = ndb.FloatProperty()
	checked_out = ndb.JsonProperty(repeated=True)

#Handles requests relating to book objects
class BookHandler(webapp2.RequestHandler):
	#POST function to create new book
	def post(self):
		#Load request body
		book_data = json.loads(self.request.body)
		#Create new Book object
		new_book = Book()

        #Set new_book's information from book_data
		new_book.title = book_data['title']
		new_book.isbn = book_data['isbn']
		new_book.author = book_data['author']
		new_book.checkedIn = book_data['checkedIn']
		new_book.genre = book_data['genre']
		new_book.put()

        #Set id from new_book's key
		new_book.id = new_book.key.urlsafe()
		new_book.put()

        #Convert new_book to dictionary format
		book_dict = new_book.to_dict()
        #Add self property to book_dict
		book_dict['self'] = '/books/' + new_book.key.urlsafe()

        #Write book_dict as response
		self.response.write(json.dumps(book_dict))
        #Set status code
		self.response.set_status(201)

    #GET function to return book(s)
	def get(self, id=None):
		#If id is specified...
		if id:
            #Find book from id
			b = ndb.Key(urlsafe = id).get()

            #Convert to dict
			b_dict = b.to_dict()
            #Add self property
			b_dict['self'] = '/books/' + id

            #Write response
			self.response.write(json.dumps(b_dict))
		
		#If id is not specified...
		else:
            #Set check filter from request field
			check = self.request.get('checkedIn')

            #Query all books and create list
			book_query = Book.query()
			all_books = book_query.fetch()
		
			#If no books, write empty brackets as response
			if len(all_books) < 1:
				self.response.out.write("[]")

			#If at least one book exists...
			else:
                #Create list to hold all books
				book_list = list()

				#If checked in books are requested...
				if check == 'true' or check == 'True':
                    #Loop through all books
					for book in all_books:
                        #Add book to book_list if checked in
						if book.checkedIn == True:
							book_list.append(book.to_dict())

				#If checked out books are requested...
				elif check == 'false' or check == 'False':
                    #Loop through all books
					for book in all_books:
                        #Add book to book_list if not checked in
						if book.checkedIn == False:
							book_list.append(book.to_dict())

				#If checkedIn status was not specified...
				else:
                    #Loop through all books and add to book_list
					for book in all_books:
						book_list.append(book.to_dict())
				
                #Write book_list as response
				self.response.write(json.dumps(book_list))

        #Set status code
		self.response.set_status(200)

	#PUT function to update all fields of a book at once
	def put(self, id=None):
		#If id is specified...
		if id:
			#Find book from id
			b = Book.query(Book.id == id).get()

			#If book is checked out, throw error and set status code
			if b.checkedIn == False:
				self.response.write('ERROR: Cannot modify checked out book.')
				self.response.set_status(409)

			#If book is not checked out...
			else:
				#Load request data into new_b
				new_b = json.loads(self.request.body)

				#Update each of b's properties from new_b, leaving blank if not specified
				if 'title' in new_b:
					b.title = new_b['title']
				else:
					b.title = ''
				if 'isbn' in new_b:
					b.isbn = new_b['isbn']
				else:
					b.isbn = ''
				if 'author' in new_b:
					b.author = new_b['author']
				else:
					b.author = ''
				b.checkedIn = True
				if 'genre' in new_b:
					b.genre = new_b['genre']
				else:
					b.genre = []
				b.put()

				#Make sure id is unchanged
				b.id = id
				b.put()

				#Convert to dictionary and add self property back
				b_dict = b.to_dict()
				b_dict['self'] = '/books/' + id

				#Write response and set status code
				self.response.write(json.dumps(b_dict))
				self.response.set_status(200)

		#If id is not specified, throw error and set status code
		else:
			self.response.write('ERROR: Please provide ID to modify a book.')
			self.response.set_status(409)

	#PATCH function to update only specified fields of a book
	def patch(self, id=None):
		#If id is specified...
		if id:
			#Find book from id
			b = Book.query(Book.id == id).get()

			#If book is checked out, throw error and set status code
			if b.checkedIn == False:
				self.response.write('ERROR: Cannot modify checked out book.')
				self.response.set_status(409)

			#If book is checked in...
			else:
				#Load request body into new_b
				new_b = json.loads(self.request.body)

				#Update each property of b that is specified by new_b
				if 'title' in new_b:
					b.title = new_b['title']
				if 'isbn' in new_b:
					b.isbn = new_b['isbn']
				if 'author' in new_b:
					b.author = new_b['author']
				if 'genre' in new_b:
					b.genre = new_b['genre']
				b.put()

				#Make sure id is unchanged
				b.id = id
				b.put()

				#Convert to dictionary
				b_dict = b.to_dict()
				#Add self property
				b_dict['self'] = '/books/' + id

				#Write response and set status code
				self.response.write(json.dumps(b_dict))
				self.response.set_status(200)

		#If no id is specified, throw error and set status code
		else:
			self.response.write('ERROR: Please provide ID to modify a book.')
			self.response.set_status(409)

	#DELETE function to remove book(s)
	def delete(self, id=None):
		#If id is specified...
		if id:
			#Find book from id
			b = Book.query(Book.id == id).get()

			#If book is checked out, throw error and set status code
			if b.checkedIn == False:
				self.response.write('ERROR: Cannot delete checked out book.')
				self.response.set_status(409)

			#If book is checked in, delete book and set status code
			else:
				self.response.write('Deleting book...')
				b.key.delete()
				self.response.set_status(200)

		#If id is not specified...
		else:
			#Fetch list of all books
			all_books = Book.query().fetch()

			#Loop through all books
			for b in all_books:
				#If book is checked out, throw error and set status code
				if b.checkedIn == False:
					self.response.write('ERROR: Cannot delete checked out book.\r\n')
					self.response.set_status(409)

				#If book is checked in, delete book
				else:
					self.response.write('Deleting book...\r\n')
					b.key.delete()

			#Set status code
			self.response.set_status(200)

#Handles requests relating to customer objects
class CustHandler(webapp2.RequestHandler):
	#POST function to create new customer
	def post(self):
		#Load request body into cust_data
		cust_data = json.loads(self.request.body)
		#Create new Customer object
		new_cust = Customer()

		#Update each property of new_cust from cust_data
		new_cust.name = cust_data['name']
		new_cust.balance = cust_data['balance']
		new_cust.checked_out = cust_data['checked_out']
		new_cust.put()

		#Set id
		new_cust.id = new_cust.key.urlsafe()
		new_cust.put()

		#Convert to dictionary
		cust_dict = new_cust.to_dict()
		#Add self property
		cust_dict['self'] = '/customers/' + new_cust.key.urlsafe()

		#Write response and set status
		self.response.write(json.dumps(cust_dict))
		self.response.set_status(201)

	#GET function to return customer(s)
	def get(self, id=None):
		#If id is specified...
		if id:
			#Find customer from id
			c = ndb.Key(urlsafe=id).get()

			#Get list of checked out books
			c_books = c.checked_out

			#Create list to hold book links
			book_list = list()

			#Loop through all books checked out by customer
			for book in c_books:
				#Set b_key and append to list of book links
				b_key = book['self']
				book_list.append(b_key)

			#Convert c to dictionary
			c_dict = c.to_dict()
			#Update c_dict's checked_out list to hold only book links
			c_dict['checked_out'] = book_list
			#Add self property
			c_dict['self'] = '/customers/' + id

			#Write response
			self.response.write(json.dumps(c_dict))
		
		#If id is not specified...
		else:
			#Get full list of customers
			cust_query = Customer.query()
			all_customers = cust_query.fetch()
		
			#If there are no customers, write empty brackets as response
			if len(all_customers) < 1:
				self.response.out.write("[]")

			#If there is at least one customer...
			else:
				#Create list to hold customers
				c_list = list()

				#Loop through all customers
				for c in all_customers:
					#Get list of checked out books
					c_books = c.checked_out

					#Create list to hold book links
					book_list = list()

					#Loop through all books checked out by customer
					for book in c_books:
						#Set b_key and append to list of book links
						b_key = book['self']
						book_list.append(b_key)

					#Convert c to dictionary	
					c_dict = c.to_dict()
					#Update c_dict's checked_out list to hold only book links
					c_dict['checked_out'] = book_list
					#Append customer to c_list
					c_list.append(c_dict)

				#Write customer list as response
				self.response.write(json.dumps(c_list))

		#Set status code
		self.response.set_status(200)

	#PUT function to update all fields of a customer at once
	def put(self, id=None):
		#If id is specified...
		if id:
			#Find customer from id
			c = Customer.query(Customer.id == id).get()

			#Load request body into new_c
			new_c = json.loads(self.request.body)
			
			#Update each of c's properties from new_c, leaving blank if not specified
			if 'name' in new_c:
				c.name = new_c['name']
			else:
				c.name = ''
			if 'balance' in new_c:
				c.balance = new_c['balance']
			else:
				c.balance = 0.0
			if 'checked_out' in new_c:
				self.response.write('ERROR: Cannot check out books using PUT.')
			c.put()

			#Make sure id is unchanged
			c.id = id
			c.put()

			#Get list of books checked out by customer
			c_books = c.checked_out

			#Create list to hold book links
			book_list = list()

			#Loop through all books checked out by customer
			for book in c_books:
				#Set b_key and append to book_list
				b_key = book['self']
				book_list.append(b_key)

			#Convert c to dictionary
			c_dict = c.to_dict()
			#Update c_dict's checked_out list to hold only book links
			c_dict['checked_out'] = book_list
			#Add self property
			c_dict['self'] = '/customers/' + id

			#Write response and set status code
			self.response.write(json.dumps(c_dict))
			self.response.set_status(200)

		#If id is not specified, throw error and set status code
		else:
			self.response.write('ERROR: Please provide ID to modify a customer.')
			self.response.set_status(409)

	#PATCH function to update only specified fields of a customer
	def patch(self, id=None):
		#If id is specified...
		if id:
			#Find customer from id
			c = Customer.query(Customer.id == id).get()

			#Load request body into new_c
			new_c = json.loads(self.request.body)
			
			#Update each property of c if specified in new_c
			if 'name' in new_c:
				c.name = new_c['name']
			if 'balance' in new_c:
				c.balance = new_c['balance']
			if 'checked_out' in new_c:
				#Do not update checked_out list
				self.response.write('ERROR: Cannot check out books using PATCH.')
				self.response.set_status(409)
			c.put()

			#Make sure id is unchanged
			c.id = id
			c.put()

			#Get list of all books checked out by customer
			c_books = c.checked_out

			#Create list to hold book links
			book_list = list()

			#Loop through all books checked out by customer
			for book in c_books:
				#Set b_key and append to book_list
				b_key = book['self']
				book_list.append(b_key)

			#Convert c to dictionary
			c_dict = c.to_dict()
			#Update c_dict's checked_out list to hold only book links
			c_dict['checked_out'] = book_list
			#Add self property
			c_dict['self'] = '/customers/' + id

			#Write response and set status
			self.response.write(json.dumps(c_dict))
			self.response.set_status(200)

		#If id is not specified, throw error and set status code
		else:
			self.response.write('ERROR: Please provide ID to modify a customer.')
			self.response.set_status(409)

	#DELETE function to remove customer(s)
	def delete(self, id=None):
		#If id is specified...
		if id:
			#Find customer from id
			c = Customer.query(Customer.id == id).get()

			#If customer has checked out books, throw error and set status
			if len(c.checked_out) > 0:
				self.response.write('ERROR: Cannot delete customer with checked out book(s).')
				self.response.set_status(409)

			#If customer has no checked out books, delete customer
			else:
				self.response.write('Deleting customer...')
				c.key.delete()
				self.response.set_status(200)

		#If id is not specified...
		else:
			#Get list of all customers
			all_customers = Customer.query().fetch()

			#Loop through all customers
			for c in all_customers:
				#If customer has checked out books, throw error
				if len(c.checked_out) > 0:
					self.response.write('ERROR: Cannot delete customer with checked out book(s).\r\n')

				#If customer has no checked out books, delete customer
				else:
					self.response.write('Deleting customer...\r\n')
					c.key.delete()

			#Set status code
			self.response.set_status(200)

#Handles requests relating to checking books in/out
class CheckHandler(webapp2.RequestHandler):
	#PUT function to check out a book to a customer
	def put(self, c_id=None, b_id=None):
		#If customer and book ids are provided...
		if c_id and b_id:
			#Get customer and book from ids
			c = ndb.Key(urlsafe=c_id).get()
			b = ndb.Key(urlsafe=b_id).get()

			#If book is already checked out, throw error and set status
			if b.checkedIn == False:
				self.response.write('ERROR: That book is already checked out.')
				self.response.set_status(409)

			#If book is not already checked out...
			else:
				self.response.write('Checking out book...')
				
				#Set book's checkedIn to indicate that it has been checked out
				b.checkedIn = False
				b.put()

				#Convert b to dictionary and add self property
				b_dict = b.to_dict()
				b_dict['self'] = '/books/' + b_id

				#Append b_dict to customer's checked_out list
				c.checked_out.append(b_dict)
				c.put()

				#Set status code
				self.response.set_status(201)

		#If customer and book ids are not provided, throw error and set status
		else:
			self.response.write('ERROR: Please provide valid IDs to check out book.')
			self.response.set_status(409)

	#DELETE function to check a book back in
	def delete(self, c_id=None, b_id=None):
		#If customer and book ids are provided...
		if c_id and b_id:
			#Find customer and book from ids
			c = ndb.Key(urlsafe=c_id).get()
			b = ndb.Key(urlsafe=b_id).get()

			#If book is already checked in, throw error and set status
			if b.checkedIn == True:
				self.response.write('ERROR: That book is already checked in.')
				self.response.set_status(409)

			#If book is not already checked in...
			else:
				#Convert b to dictionary and add self property
				b_dict = b.to_dict()
				b_dict['self'] = '/books/' + b_id

				self.response.write('Checking in book...')

				#Remove b_dict from customer's checked_out list
				c.checked_out.remove(b_dict)
				c.put()

				#Update b's checkedIn to indicate that it is no longer checked in
				b.checkedIn = True
				b.put()

				#Set status code
				self.response.set_status(200)
		
		#If customer and book ids are not provided, throw error and set status
		else:
			self.response.write('ERROR: Please provide valid IDs to check in book.')
			self.response.set_status(409)

	#GET function to return list of books checked out by a customer
	def get(self, c_id=None, b_id=None):
		#If customer id is specified...
		if c_id:
			#Find customer from id
			c = ndb.Key(urlsafe=c_id).get()

			#If book id is specified...
			if b_id:
				#Find book from id
				b = ndb.Key(urlsafe=b_id).get()

				#Convert b to dictionary and add self property
				b_dict = b.to_dict()
				b_dict['self'] = '/books/' + b_id

				#Write b_dict as response (same as simply requesting /book/:b_id)
				self.response.write(json.dumps(b_dict))

			#If book id is not specified...
			else:
				#Convert c to dictionary
				c_dict = c.to_dict()

				#Write c's checked_out list as response
				self.response.write(json.dumps(c_dict['checked_out']))

		#Set status code
		self.response.set_status(200)

#Handles requests sent to main page
class MainPage(webapp2.RequestHandler):
	#GET function to handle GET request to homepage
    def get(self):
    	#Print welcome message and set status
        self.response.write("This is the library homepage!")
        self.response.set_status(200)

    #DELETE function to delete all books and customers
    def delete(self):
        self.response.write("Deleting all books and customers...")

        #Get list of all books
    	book_query = Book.query()
    	all_books = book_query.fetch()

    	#Get list of all customers
    	customer_query = Customer.query()
    	all_customers = customer_query.fetch()

 
    	#Loop through all books and customers and delete each
    	for b in all_books:
    		b.key.delete()
    	for c in all_customers:
    		c.key.delete()
	
		#Set status code
		self.response.set_status(200)

#Code to allow PATCH requests
allowed_methods = webapp2.WSGIApplication.allowed_methods
new_allowed_methods = allowed_methods.union(('PATCH',))
webapp2.WSGIApplication.allowed_methods = new_allowed_methods

#Handling possible URLs
app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/books', BookHandler),
    ('/books/(.*)', BookHandler),
    ('/customers', CustHandler),
    ('/customers/(.*)/books', CheckHandler),
    ('/customers/(.*)/books/(.*)', CheckHandler),
    ('/customers/(.*)', CustHandler)
    ], debug=True)
