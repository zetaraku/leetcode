// Title: Bulls and Cows
// Description:
//     You are playing the [Bulls and Cows](https://en.wikipedia.org/wiki/Bulls_and_Cows) game with your friend.
//     You write down a secret number and ask your friend to guess what the number is.
//     When your friend makes a guess, you provide a hint with the following info:
//         The number of "bulls", which are digits in the guess that are in the correct position.
//         The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position.
//             Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
//     Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
//     The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows.
//     Note that both secret and guess may contain duplicate digits.
// Link: https://leetcode.com/problems/bulls-and-cows/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        assert(secret.size() == guess.size());

        const std::size_t N = secret.size();

        std::vector<std::size_t> unmatchedSecretDigits(10, 0);

        // count every unmatched digit in secret
        for (std::size_t i = 0; i != N; ++i) {
            if (secret[i] != guess[i]) {
                std::size_t &unmatchedSecretDigit = unmatchedSecretDigits[secret[i] - '0'];
                ++unmatchedSecretDigit;
            }
        }

        std::size_t bullsCount = 0, cowsCount = 0;

        // for each position in guess
        for (std::size_t i = 0; i != N; ++i) {
            if (guess[i] == secret[i]) {
                // if the digit in guess is the same as the digit in secret, match a bull
                ++bullsCount;
            } else {
                // otherwise, use an unmatched digit in secret (if any) to match a cow
                std::size_t &unmatchedSecretDigit = unmatchedSecretDigits[guess[i] - '0'];
                if (unmatchedSecretDigit != 0) --unmatchedSecretDigit, ++cowsCount;
            }
        }

        return std::to_string(bullsCount) + "A" + std::to_string(cowsCount) + "B";
    }
};
