const assert = require('assert');

// Example test case
function add(a, b) {
  return a + b;
}

try {
  // Test case 1
  assert.strictEqual(add(2, 2), 4);

  // Test case 2
  assert.strictEqual(add(-1, 5), 4);

  // Additional test cases...
  
  console.log('All tests passed successfully!');
} catch (error) {
  console.error('Test failed:', error);
  process.exit(1); // Exit with a non-zero status code to indicate test failure
}
