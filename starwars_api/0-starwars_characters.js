#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

function getCharacterName (url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true }, (error, response, body) => {
      error
        ? reject(error)
        : (response.statusCode !== 200) ? reject(new Error(`Failed to get character data: ${response.statusCode}`)) : resolve(body.name);
    });
  });
}

request(url, { json: true }, async (error, response, body) => {
  if (error) return console.log(error);
  if (response.statusCode !== 200) return console.log(`Failed to get film data: ${response.statusCode}`);

  const characterUrls = body.characters;
  try {
    const characterNames = await Promise.all(characterUrls.map(url => getCharacterName(url)));
    characterNames.forEach(name => console.log(name));
  } catch (error) {
    console.log(error);
  }
});
