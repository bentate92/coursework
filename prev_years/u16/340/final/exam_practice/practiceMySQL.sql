SELECT p.productCode, p.productName FROM products p
INNER JOIN orderdetails od ON p.productCode=od.productCode
INNER JOIN orders o ON od.orderNumber=o.orderNumber
INNER JOIN customers c ON o.customerNumber=c.customerNumber
WHERE c.customerName='Herkku Gifts' AND o.orderDate='2003-11-18';

SELECT p.productCode, COUNT(od.orderNumber) FROM products p
INNER JOIN orderdetails od ON p.productCode=od.productCode
GROUP BY p.productCode;

SELECT customerNumber, customerName FROM customers
WHERE customerNumber NOT IN (
	SELECT customerNumber FROM orders o
	INNER JOIN orderdetails od ON o.orderNumber=od.orderNumber
	INNER JOIN products p ON p.productCode=od.productCode
	WHERE p.productName='2001 Ferrari Enzo'
);

SELECT p.productCode, SUM(quantityOrdered) FROM products p
LEFT JOIN (
	SELECT od.productCode, od.quantityOrdered FROM orderdetails od
	INNER JOIN orders o ON od.orderNumber=o.orderNumber
	INNER JOIN customers c ON c.customerNumber=o.customerNumber
	WHERE c.customerName='Mini Wheels Co.'
) AS tbl ON tbl.productCode=p.productCode
GROUP BY p.productCode;

SELECT e.firstName, e.lastName FROM employees 
INNER JOIN offices o ON e.officeCode=o.officeCode
WHERE o.city='Boston' 
AND e.reportsTo IN(
	SELECT employeeNumber FROM employees
	WHERE firstName='Anthony' AND lastName='Bow'
);
