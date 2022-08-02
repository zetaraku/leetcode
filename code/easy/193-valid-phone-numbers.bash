# Title: Valid Phone Numbers
# Description:
#     Given a text file file.txt that contains a list of phone numbers (one per line), write a one-liner bash script to print all valid phone numbers.
#     You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)
#     You may also assume each line in the text file must not contain leading or trailing white spaces.
# Link: https://leetcode.com/problems/valid-phone-numbers/

# Read from the file file.txt and output all valid phone numbers to stdout.
grep --perl-regexp --line-regexp '\d{3}-\d{3}-\d{4}|\(\d{3}\) \d{3}-\d{4}' <file.txt
