#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define NUM_FIELDS 4
struct SplitLine
{
  std::string fields[NUM_FIELDS];
};

/* DONT MAKE ANY CHANGES ABOVE THIS LINE */
using namespace std;
/* If you wish you can include any more files here.
   (from standard libraries only) */

std::map<std::string, int> processData(std::vector<struct SplitLine> data)
{

  map<string, int> ret_val;         //This will store the result
  map<string, int> constituency_id; //This maps the constituency with the largest id in it, till the current iteration
  for (SplitLine &elem : data)
  {
    auto curr_data = elem.fields;

    string constituency = curr_data[2];
    int id = stoi(curr_data[0]); //Change string to integer
    int votes = stoi(curr_data[3]);

    /**
     * Two cases are possible:
     * 1) We have not encountered this "constituency" yet.
     * 2) If we have already encountered this constituency before, we check if the current "id" is greater than the already 
     * present "id" in the map, for that "constituency".
     * 
     * If any of the above two cases are true, update the votes in the "ret_val" map, and also map the "constituency" to 
     * its new "id" in the "constituency_id" map,
     */
    if (constituency_id.count(constituency) == 0 || constituency_id[constituency] < id)
    {
      ret_val[constituency] = votes;
      constituency_id[constituency] = id;
    }
  }
  return ret_val;
}

/* DONT MAKE ANY CHANGES BELOW THIS LINE */

int main(void)
{
  std::ifstream in("input.txt");
  std::vector<struct SplitLine> input_data;
  while (in)
  {
    struct SplitLine line;
    for (int i = 0; i < NUM_FIELDS; i++)
    {
      if (i == NUM_FIELDS - 1)
        std::getline(in, line.fields[i]);
      else
        std::getline(in, line.fields[i], ',');
    }
    if (line.fields[0] != "")
      input_data.push_back(line);
  }
  std::ofstream out("output.txt");
  std::map<std::string, int> ret_val = processData(input_data);
  for (std::map<std::string, int>::iterator it = ret_val.begin();
       it != ret_val.end();
       it++)
  {
    out << it->first << ": " << it->second << std::endl;
  }
  return 0;
}
