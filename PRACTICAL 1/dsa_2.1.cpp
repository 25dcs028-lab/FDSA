#include<iostream>
using namespace std;

int linearsearch(string plates[], int n, string key)
{
    for (int i = 0; i < n; i++)
    {
        if (plates[i] == target)
        {
            return i;

        }
    }
    return -1;

}
int recursivelinearsearch(string plates[], string target, int index)
{
    if (index >= n)
    {
        return -1;

    }
    if (plates[index] == target)
    {
        return index;
    }
    return recursivelinearsearch(plates, target, index + 1);
}
int main(){
    string plates[5] = {}
}