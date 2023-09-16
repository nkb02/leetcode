/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let cnt = init;
    return{
        increment(){
            return ++init;
        },
        decrement(){
            return --init;
        },
        reset(){
            init = cnt;
            return cnt;
        }
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

//  let count = init;

//   return {
//     increment() {
//       return ++count;
//     },
//     decrement() {
//       return --count;
//     },
//     reset() {
//       count = 0;
//       return count;
//     }
//   };