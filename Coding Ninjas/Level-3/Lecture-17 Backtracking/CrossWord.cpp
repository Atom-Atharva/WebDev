// I DONT KNOW WHY IT IS NOT WORKING :(

#include <iostream>
using namespace std;
#include <vector>

void print(char **crossword)
{
    // Print Crossword--
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << crossword[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}

bool isValidVertical(char **crossword, string word, int row, int col)
{
    int i, j;
    for (i = 0, j = row; i < word.length() && j < 10; i++, j++)
    {
        if (crossword[j][col] == '-' || crossword[j][col] == word[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if (i != word.length())
    {
        return false;
    }
    return true;
}

bool isValidHorizontal(char **crossword, string word, int row, int col)
{
    int i, j;
    for (i = 0, j = col; i < word.length() && j < 10; i++, j++)
    {
        if (crossword[row][j] == '-' || crossword[row][j] == word[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if (i != word.length())
    {
        return false;
    }
    return true;
}

void setVertical(char **crossword, string word, int row, int col, vector<bool> *setter)
{
    for (int i = row, j = 0; j < word.length(); j++, i++)
    {
        if (crossword[i][col] == '-')
        {
            setter->push_back(1);
            crossword[i][col] = word[j];
        }
        else
        {
            setter->push_back(0);
        }
    }
    return;
}

void setHorizontal(char **crossword, string word, int row, int col, vector<bool> *setter)
{
    for (int i = col, j = 0; j < word.length(); j++, i++)
    {
        if (crossword[row][i] == '-')
        {
            setter->push_back(1);
            crossword[row][i] = word[j];
        }
        else
        {
            setter->push_back(0);
        }
    }
    return;
}

void resetVertical(char **crossword, vector<bool> *setter, int row, int col)
{
    for (int i = 0, j = row; i < setter->size(); i++, j++)
    {
        if (setter->at(i) == true)
        {
            crossword[j][col] = '-';
        }
    }
    return;
}

void resetHorizontal(char **crossword, vector<bool> *setter, int row, int col)
{
    for (int i = 0, j = col; i < setter->size(); i++, j++)
    {
        if (setter->at(i) == true)
        {
            crossword[row][j] = '-';
        }
    }
    return;
}

bool puzzle(char **crossword, vector<string> *words, int ind)
{
    // Base Case--
    if (ind == words->size())
    {
        return true;
    }

    // Search for Inserting Places--
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (crossword[i][j] == '-' || crossword[i][j] == words->at(ind)[0])
            {
                // Check for Vertical--
                if (isValidVertical(crossword, words->at(ind), i, j))
                {
                    vector<bool> *setter = new vector<bool>();

                    // Set Vertical--
                    setVertical(crossword, words->at(ind), i, j, setter);

                    // Reccursive Call--
                    bool valid = puzzle(crossword, words, ind + 1);

                    // Reset Vertical--
                    if (valid)
                    {
                        return true;
                    }
                    else
                    {
                        resetVertical(crossword, setter, i, j);
                    }
                }

                // Check for Horizontal--
                if (isValidHorizontal(crossword, words->at(ind), i, j))
                {
                    vector<bool> *setter = new vector<bool>();

                    // Set Horizontal--
                    setHorizontal(crossword, words->at(ind), i, j, setter);

                    // Reccursive Call--
                    bool valid = puzzle(crossword, words, ind + 1);

                    // Reset Horizontal--
                    if (valid)
                    {
                        return true;
                    }
                    else
                    {
                        resetHorizontal(crossword, setter, i, j);
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    // Cross Word--
    char **crossword = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        crossword[i] = new char[10];
        for (int j = 0; j < 10; j++)
        {
            cin >> crossword[i][j];
        }
    }

    vector<string> *words;

    // Words--
    string s, w;
    cin >> w;

    for (int i = 0; i < w.length(); i++)
    {
        if (w[i] == ';')
        {
            words->push_back(s);
            s = "";
        }
        else
        {
            s = s + w[i];
        }
    }
    words->push_back(s);

    // Insert First Word--
    bool valid = puzzle(crossword, words, 0);
    if (valid)
    {
        print(crossword);
    }
    else
    {
        print(crossword);
    }

    return 0;
}