#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
	vector<list<string>> buffer(10);
	vector<list<string>> buffer2(10);
	vector<list<string>> *buffers[] = {&buffer,&buffer2};
	vector<list<string>> *result;
	int num{ 0 };
	int maxLen = 0;
	int curpo = 0;
	string *input;
	while (cin>>num) {
		curpo = 0;
		result = buffers[(curpo++)%2];
		for (long int i = 0; i < num; i++) {
			cin >> *(input =new string);
			if (maxLen<input->size())
			{
				maxLen = input->size();
			}
			(*result)[*(input->rbegin()) - '0'].push_back(*input);
		}
		vector<list<string>> *source = result;
		for (int j = 0; j < maxLen-1; j++)
		{
			vector<list<string>> *newBuffer = buffers[(curpo++)%2];
			/*if (result!=&buffer)
			{
				vector<list<string>>().swap(*result);
				result->resize(10);
			}*/
			result = newBuffer;
			for (int i = 0; i < 10; i++)
			{
				if (!(*source)[i].empty())
				{
					list<string>::iterator it = (*source)[i].begin();
					while (it!=(*source)[i].end())
					{
						if (it->size() <= (1+j) )
						{
							(*result)[0].push_back(*it);
						}
						else
						{
							string::reverse_iterator sit = (*it).rbegin();
							sit += j+1;
							(*result)[*(sit)-'0'].push_back(*it);
						}
						it++;
					}
				}
			}
			source = newBuffer;
			vector<list<string>>().swap(*(buffers[curpo % 2]));
			(*buffers[curpo % 2]).resize(10);
		}
		for (int k = 0; k < 10; k++)
		{
			if (!(*result)[k].empty())
			{
				list<string>::iterator it = (*result)[k].begin();
				while (it!=(*result)[k].end())
				{
					std::cout << *it << " ";
					it++;
				}
			}
		}
		vector<list<string>>().swap(buffer);
		buffer.resize(10);
		vector<list<string>>().swap(buffer2);
		buffer2.resize(10);
		std::cout << endl;
		maxLen = 0;
	}
	return 0;
}