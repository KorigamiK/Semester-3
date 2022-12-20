CREATE TABLE CUSTOMERS
(
    cust_num int PRIMARY KEY,
    cust_lname varchar(20),
    cust_fname varchar(20),
    cust_balance int
);

CREATE TABLE PRODUCT
(
    prod_num int PRIMARY KEY,
    prod_name varchar(20),
    price int
);

CREATE TABLE INVOICE
(
    inv_num int,
    prod_num int,
    cust_num int,
    inv_date date,
    unit_sold int,
    inv_amount int,
    PRIMARY KEY (inv_num, prod_num, cust_num, inv_date),
    FOREIGN KEY (prod_num) REFERENCES PRODUCT(prod_num),
    FOREIGN KEY (cust_num) REFERENCES CUSTOMERS(cust_num)
);