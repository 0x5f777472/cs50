SELECT title, rating FROM movies, ratings WHERE [year] = "2010" AND ratings.movie_id = movies.id ORDER BY ratings;
