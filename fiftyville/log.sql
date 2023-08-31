-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime scene descriptions say stolen at 7/28 10:15 am at bakery
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- before 10:15 am, leggett street, withdrawing. 10 minutes within the theft drive away. call for less than 1 minute, earliest flight tomorrow, accomplice buys ticket.
SELECT * FROM interviews WHERE month = 7 AND day = 28;

-- bakery logs:
SELECT hour, minute, activity, license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND activity = 'exit';
--get flights the car owner ahve been on
SELECT flight_id FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND activity = 'exit'));
SELECT id FROM flights WHERE origin_airport_id = 8 AND month = 7 AND day = 29;
-- either flight 18 or 36
