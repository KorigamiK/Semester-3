CREATE TABLE SAILORS (
    sid INTEGER PRIMARY KEY,
    sname VARCHAR(20),
    rating INTEGER,
    date_of_birth DATE
);

CREATE TABLE BOATS (
    bid INTEGER PRIMARY KEY,
    bname VARCHAR(20),
    color VARCHAR(20)
);

CREATE TABLE RESERVES (
    sid INTEGER,
    bid INTEGER,
    date DATE,
    time_slot INTEGER,
    PRIMARY KEY (sid, bid, date, time_slot)
);