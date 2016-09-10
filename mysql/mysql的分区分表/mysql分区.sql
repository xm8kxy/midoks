--RANGE分区
CREATE TABLE employees(
	`id` INT NOT NULL,
　	`fname` VARCHAR(30),
　　`iname` VARCHAR(30),
　　`hired` DATE NOT NULL DEFAULT '1970-01-01',
　　`separated` DATE NOT NULL DEFAULT '9999-12-31',
　　`job_code` INT NOT NULL,
　　`store_id` INT NOT NULL
)
PARTITION BY RANGE(store_id)(
　　　PARTITION p0 VALUES LESS THAN(6),
　　　PARTITION p0 VALUES LESS THAN(11),
　　　PARTITION p0 VALUES LESS THAN(16),
　　　PARTITION p0 VALUES LESS THAN(21),
);
--LIST分区
CREATE TABLE employees(
　`id` INT NOT NULL,
　`fname` VARCHAR(30),
　`iname` VARCHAR(30),
　`hired` DATE NOT NULL DEFAULT '1970-01-01',
　`separated` DATE NOT NULL DEFAULT '9999-12-31',
　`job_code` INT NOT NULL,
　`store_id` INT NOT NULL
)
PARTITION BY LIST(store_id)(
	PARTITION pNorth VALUES IN (3,5,6,9,17),
　　PARTITION pNorth VALUES IN (1,2,10,11,19),
　　PARTITION pNorth VALUES IN (4,12,13,14,18),
　　PARTITION pNorth VALUES IN (7,8,15,16),
);
--HASH 分区
CREATE TABLE employees(
	`id` INT NOT NULL,
　　`fname` VARCHAR(30),
　　`iname` VARCHAR(30),
　　`hired` DATE NOT NULL DEFAULT '1970-01-01',
　　`separated` DATE NOT NULL DEFAULT '9999-12-31',
　　`job_code` INT NOT NULL,
　　`store_id` INT NOT NULL
)
PARTITION BY HASH(YEAR(`hired`))
PARTITION 4;
　　　



