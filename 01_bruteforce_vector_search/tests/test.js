const addon = require('../build/Release/vector_engine');


// Generate random vector
function randomVec(dim) {
  return Array.from({ length: dim }, () => Math.random());
}

// Insert 500 vectors
console.time("insert_500");

for (let i = 0; i < 500; i++) {
  const vec = randomVec(5); // 5D vectors
  addon.insert(vec, "vec_" + i);
}

console.timeEnd("insert_500");

// Run multiple queries
console.log("\n--- SEARCH TESTS ---");

console.time("search_1");
console.log("Query 1:", addon.search(randomVec(5)));
console.timeEnd("search_1");

console.time("search_2");
console.log("Query 2:", addon.search(randomVec(5)));
console.timeEnd("search_2");

console.time("search_3");
console.log("Query 3:", addon.search(randomVec(5)));
console.timeEnd("search_3");