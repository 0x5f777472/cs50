SELECT title FROM movies JOIN stars on movies.id = stars.movie_id JOIN people ON stars.person_id = people.id WHERE name = "Bradley Cooper" AND name = "Jennifer Lawrence";
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Bradley Cooper" OR "Jennifer Lawrence"));