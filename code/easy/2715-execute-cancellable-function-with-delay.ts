// Title: Execute Cancellable Function With Delay
// Description:
//     Given a function fn, an array or arguments args, and a timeout t in milliseconds, return a cancel function cancelFn.
//     After a delay of t, fn should be called with args passed as parameters unless cancelFn was called first. In that case, fn should never be called.
// Link: https://leetcode.com/problems/execute-cancellable-function-with-delay/

function cancellable(fn: Function, args: any[], t: number): Function {
  let cancelled = false;

  setTimeout(() => {
    if (!cancelled) fn(...args);
  }, t);
  
  return () => {
    cancelled = true;
  };
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 5
 *  const args = [2], t = 20, cancelT = 50
 *
 *  const log = (...argsArr) => {
 *      result.push(fn(...argsArr))
 *  }
 *       
 *  const cancel = cancellable(fn, args, t);
 *           
 *  setTimeout(() => {
 *     cancel()
 *     console.log(result) // [{"time":20,"returned":10}]
 *  }, cancelT)
 */
