// https://leetcode.com/problems/simplify-path/

// Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

// In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

// The canonical path should have the following format:

// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
// Return the simplified canonical path.

/**********************************************IMP QUESTION************************************************************************/

#include <iostream>
using namespace std;

// Move on String in Reverse Order--
class Solution
{
public:
    string simplifyPath(string path)
    {
        string ans = "";
        int back = 0;

        for (int i = path.size() - 1; i >= 0; i--)
        {
            // Content between /.../
            string temp = "";
            while (i >= 0 && path[i] != '/')
            {
                temp = path[i] + temp;
                i--;
            }

            if (temp == "" || temp == ".")
            {
                continue;
            }

            if (temp == "..")
            {
                back++;
            }
            else if (back > 0)
            {
                back--;
            }
            else
            {
                ans = temp + ans;
                ans = '/' + ans;
            }
        }
        if (ans == "")
        {
            return "/";
        }
        return ans;
    }
};
