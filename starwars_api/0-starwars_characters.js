#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

function getCharacterName(url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true }, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(body.name);
      }
    });
  });
}

request(url, { json: true }, async (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const characterUrls = body.characters;
  const characterPromises = characterUrls.map(url => getCharacterName(url));

  try {
    const characterNames = await Promise.all(characterPromises);
    characterNames.forEach(name => console.log(name));
  } catch (error) {
    console.error(error);
  }
});
