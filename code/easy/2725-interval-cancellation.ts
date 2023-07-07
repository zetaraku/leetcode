// Title: Interval Cancellation
// Description:
//     Given a function fn, an array of arguments args, and an interval time t, return a cancel function cancelFn.
//     The function fn should be called with args immediately and then called again every t milliseconds until cancelFn is called. 
// Link: https://leetcode.com/problems/interval-cancellation/

function cancellable(fn: Function, args: any[], t: number): Function {
  fn(...args);

  const intervalId = setInterval(() => {
    fn(...args);
  }, t);
  
  return () => {
    clearInterval(intervalId);
  };
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 2
 *  const args = [4], t = 20, cancelT = 110
 *
 *  const start = performance.now()
 *
 *  const log = (...argsArr) => {
 *		const val = fn(...argsArr)
 *      result.push({"time": Math.floor(performance.now() - start), "returned": fn(...argsArr)})
 *  }
 *       
 *  const cancel = cancellable(log, args, t);
 *           
 *  setTimeout(() => {
 *     cancel()
 *     console.log(result) // [
 *                         //      {"time":0,"returned":8},
 *                         //      {"time":20,"returned":8},
 *                         //      {"time":40,"returned":8},           
 *                         //      {"time":60,"returned":8},
 *                         //      {"time":80,"returned":8},
 *                         //      {"time":100,"returned":8}
 *                         //  ]
 *  }, cancelT)
 */
