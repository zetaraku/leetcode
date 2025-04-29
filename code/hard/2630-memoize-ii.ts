// Title: Memoize II
// Description:
//     Given a function fn, return a memoized version of that function.
//     A memoized function is a function that will never be called twice with the same inputs. Instead it will return a cached value.
//     fn can be any function and there are no constraints on what type of values it accepts. Inputs are considered identical if they are === to each other.
// Link: https://leetcode.com/problems/memoize-ii/

type Fn = (...params: any[]) => any;

class MultiKeyMap<K extends any[], V> {
    value: V;
    hasValue: boolean;
    children: Map<K[number], MultiKeyMap<K, V>>;

    constructor() {
        this.value = undefined;
        this.hasValue = false;
        this.children = new Map();
    }

    has(keys: K): boolean {
        let node: MultiKeyMap<K, V> = this;

        for (let key of keys) {
            if (!node.children.has(key)) {
                return false;
            }

            node = node.children.get(key);
        }

        return node.hasValue;
    }

    get(keys: K): V {
        let node: MultiKeyMap<K, V> = this;

        for (let key of keys) {
            if (!node.children.has(key)) {
                return undefined;
            }

            node = node.children.get(key);
        }

        return node.value;
    }

    set(keys: K, value: V): void {
        let node: MultiKeyMap<K, V> = this;

        for (let key of keys) {
            if (!node.children.has(key)) {
                node.children.set(key, new MultiKeyMap<K, V>());
            }

            node = node.children.get(key);
        }

        node.value = value;
        node.hasValue = true;
    }
}

function memoize(fn: Fn): Fn {
    const cache = new MultiKeyMap<any[], any>();

    return function (...args) {
        if (cache.has(args)) return cache.get(args);

        const result = fn(...args);

        cache.set(args, result);

        return result;
    };
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
