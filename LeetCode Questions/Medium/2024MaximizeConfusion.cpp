// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

// You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

// Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
// Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

#include <iostream>
using namespace std;

// Sliding Window Problem
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        // Two Pointers--
        int l = 0, r = 0;

        // Operate on False, i.e., only Trues--
        int tLen = 0;
        int count = 0;
        while (r < answerKey.length())
        {
            if (count > k)
            {
                if (answerKey[l] == 'F')
                {
                    count--;
                }
                l++;
            }
            else
            {
                if (answerKey[r] == 'F')
                {
                    count++;
                }
                r++;
            }

            if (count <= k)
            {
                tLen = max(tLen, r - l);
            }
        }

        // Operate on True, i.e., only False--
        int fLen = 0;
        count = 0;
        while (r < answerKey.length())
        {
            if (count > k)
            {
                if (answerKey[l] == 'T')
                {
                    count--;
                }
                l++;
            }
            else
            {
                if (answerKey[r] == 'T')
                {
                    count++;
                }
                r++;
            }

            if (count <= k)
            {
                fLen = max(fLen, r - l);
            }
        }

        return max(fLen, tLen);
    }
};