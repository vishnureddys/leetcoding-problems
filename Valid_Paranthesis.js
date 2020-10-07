/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (str) {
    let stack = [];
    let flag = true;

    if (str.length === 1)
        return false

    for (let index = 0; index < str.length; index++) {
        const element = str[index];
        if (element === '(' || element === '[' || element === '{')
            stack.push(element);
        else {
            let last = stack.pop();
            if ((last !== '(' && element === ')') || (last !== '[' && element === ']') || (last !== '{' && element === '}')) {
                flag = false;
                break;
            }
        }
    }

    if (stack.length != 0)
        flag = false;

    return flag;
};