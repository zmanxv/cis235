
-- Create schema for final project db
CREATE SCHEMA `final_project_database` ;

-- Replace with account classes
-- Create table for final project db
-- Product table example for reference
CREATE TABLE `account_table`.`account` (
       `idproduct` INT NOT NULL AUTO_INCREMENT , 
       `name` VARCHAR(45) NOT NULL ,
       `price` FLOAT NOT NULL , 
       `created` DATETIME NOT NULL , 
       PRIMARY KEY (`idproduct`) );

