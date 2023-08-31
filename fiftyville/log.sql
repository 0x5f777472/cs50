-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime scene descriptions say stolen at 7/28 10:15 am at bakery
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- bakery logs:
SELECT minute, activity, license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10;