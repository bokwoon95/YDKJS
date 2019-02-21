// "use strict";
var isStrict = (function() { return !this; })();
function prompt(question, callback) {
  var stdin = process.stdin,
    stdout = process.stdout;

  stdin.resume();
  stdout.write(question);

  stdin.once('data', function (data) {
    callback(data.toString().trim());
  });
}

function foo() {
	console.log( a );
}

var a = 2;

foo.call( null ); // 2
// function foo(a,b) {
// 	console.log( "a:" + this.a + ", b:" + this.b );
// }

// spreading out array as parameters
// foo.apply( null, [2, 3] ); // a:2, b:3

// currying with `bind(..)`
// var bar = foo.bind( null, 2 );
// bar( 3 ); // a:2, b:3

// var MyModules = function Manager() {
//   var modules = {};

//   /*
//    * 'name' is the name of the function you're defining
//    * 'deps' is a key value list of the dependencies that this function relies on. The key is the name of the dependency function, the value is ???
//    * 'impl' is ???
//    *
//    */
//   function define(name, deps, impl) {
//     for (var i=0; i<deps.length; i++) {
//       deps[i] = modules[deps[i]];
//     }
//     modules[name] = impl.apply( impl, deps );
//   }

//   function get(name) {
//     return modules[name];
//   }

//   return {
//     define: define,
//     get: get
//   };
// }();

// MyModules.define(
//   "bar",
//   [],
//   function(){
//     function hello(who) {
//       return "Let me introduce: " + who;
//     }

//     return {
//       hello: hello
//     };
//   }
// );

// MyModules.define(
//   "foo",
//   ["bar"],
//   function(bar){
//     var hungry = "hippo";

//     function awesome() {
//       console.log( bar.hello( hungry ).toUpperCase() );
//     }

//     return {
//       awesome: awesome
//     };
//   }
// );

// // var bar = MyModules.get( "bar" );
// // var foo = MyModules.get( "foo" );

// console.log(
//   MyModules.get("bar").hello( "hippo" )
// ); // Let me introduce: hippo

// MyModules.get("foo").awesome(); // LET ME INTRODUCE: HIPPO
