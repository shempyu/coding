void main(){
//   print('hello,  WOrld!');
// var name = 'Voyager I';
// var year = 1977;
// var antennaDiameter = 3.7;
var flybyObjects = ['Jupiter', 'Saturn', 'Uranus', 'Neptune'];
// var image = {
//   'tags': ['saturn'],
//   'url': '//path/to/saturn.jpg'
// };

// if (year >= 2001) {
//   print('21st century');
// } else if (year >= 1901) {
//   print('20th century');
// }

// for (final object in flybyObjects) {
//   print(object);
// }

// for (int month = 1; month <= 12; month++) {
//   print(month);
// }

// while (year < 2016) {
//   year += 1;
// } print(year);

int fibonacci(int n) {
  if (n == 0 || n == 1) return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

var result = fibonacci(2);
print(result);

flybyObjects.where((name) => name.contains('turn')).forEach(print);
  
}