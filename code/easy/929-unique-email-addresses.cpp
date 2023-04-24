// Title: Unique Email Addresses
// Description:
//     Every valid email consists of a local name and a domain name, separated by the '@' sign.
//     Besides lowercase letters, the email may contain one or more '.' or '+'.
//     If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.
//     If you add a plus '+' in the local name, everything after the first plus sign will be ignored.
//     Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.
// Link: https://leetcode.com/problems/unique-email-addresses/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::string normalizeEmail(std::string &email) {
        std::string result = "";

        auto it = email.begin();

        for (char c; c = *it, c != '@'; ++it) {
            if (c == '+') break;
            if (c == '.') continue;
            result += c;
        }
        
        while (*it != '@') ++it;

        result.append(it, email.end());

        return result;
    }

    int numUniqueEmails(std::vector<std::string> &emails) {
        std::unordered_set<std::string> uniqueEmails;

        for (std::string &email: emails) {
            uniqueEmails.insert(normalizeEmail(email));
        }

        return uniqueEmails.size();
    }
};
