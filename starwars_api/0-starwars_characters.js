#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (error, response, body) => {
  error ? console.error(error) : handleFilmData(body);
});

function handleFilmData(body) {
  const film = JSON.parse(body);
  const charactersLink = film.characters;

  charactersLink.forEach((characterUrl) => {
    request(characterUrl, (error, response, body) => {
      error ? console.error(error) : console.log(JSON.parse(body).name);
    });
  });
}
