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
-- flight 36.
-- get people (Stack overflow so split up (sorry if reading this))
SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate IN (SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE caller IN (SELECT phone_number FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE account_number IN (SELECT account_number FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60))) AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'))) AND flight_id = 36)) AND day=28 AND duration < 60)) AND day=28 AND hour=10 AND minute<25 AND minute>15);
-- this returns (367) 555-5533
SELECT caller, receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND day=28 AND duration<60;
