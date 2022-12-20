ALTER TABLE reserves
ADD FOREIGN KEY (sid) REFERENCES sailors(sid);

ALTER TABLE reserves
ADD FOREIGN KEY (bid) REFERENCES boats(bid);