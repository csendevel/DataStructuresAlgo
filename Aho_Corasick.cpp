/*
Че пацаны физтех?
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃＼○／
┛┗┛┗┛┃ / /
┓┏┓┏┓┃ノ
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃┓
┛┗┛┗┛┃┃
*/
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#define N 1000000

using namespace std;

const int ALP = 26;

struct bohr_node {
	bool leaf;
	int pattern_num; //number of line that ended in this node
	int next_ch[ALP]; //next characters
	int	suff_links[ALP];
	int suff_link;
	int g_suff_link; //good suffix link
	int parent;
	char par_symb; //symbol on edge from parent node to current

	bohr_node() {
		leaf = false;
		pattern_num = suff_link = g_suff_link = parent = -1;
		memset(next_ch, -1, sizeof(next_ch));
		memset(suff_links, -1, sizeof(suff_links));
	}
};

vector <bohr_node> bohr;
vector <string> patterns;

void add_string(string& s, int pat_num) {
	int it = 0;
	for (int i = 0; i < s.size(); i++) {
		int c = (int)(s[i] - 'a');
		if (bohr[it].next_ch[c] == -1) {
			bohr_node p;
			p.parent = it;
			p.par_symb = s[i] - 'a';
			bohr.push_back(p);
			bohr[it].next_ch[c] = bohr.size() - 1;
		}
		it = bohr[it].next_ch[c];
	}
	bohr[it].leaf = true;
	bohr[it].pattern_num = pat_num;
}

bool pattern_entry(string& s) {
	int it = 0;
	for (int i = 0; i < s.size(); i++) {
		int c = (int)(s[i] - 'a');
		if (bohr[it].next_ch[c] == -1)
			return false;
		it = bohr[it].next_ch[c];
	}
	return bohr[it].leaf;
}

int get_transition(int v, char c);

int get_suffix_link(int v) {
	if (bohr[v].suff_link == -1) {
		if (v == 0 || bohr[v].parent == 0)
			bohr[v].suff_link = 0;
		else
			bohr[v].suff_link = get_transition(get_suffix_link(bohr[v].parent), bohr[v].par_symb);
	}
	return bohr[v].suff_link;
}

int get_transition(int v, char c) {
	if (bohr[v].suff_links[c] == -1) {
		if (bohr[v].next_ch[c] != -1)
			bohr[v].suff_links[c] = bohr[v].next_ch[c];
		else {
			if (v == 0)
				bohr[v].suff_links[c] = 0;
			else
				bohr[v].suff_links[c] = get_transition(get_suffix_link(v), c);
		}
	}
	return bohr[v].suff_links[c];
}

int get_good_suff_link(int v) {
	if (bohr[v].g_suff_link == -1) {
		int next_suff = get_suffix_link(v);

		if (next_suff == 0) bohr[v].g_suff_link = 0;
		else {
			if (bohr[next_suff].leaf == false)
				bohr[v].g_suff_link = get_good_suff_link(next_suff);
			else
				bohr[v].g_suff_link = next_suff;
		}
	}
	return bohr[v].g_suff_link;
}

int main() {
	//initialization
	bohr_node v;
	v.parent = 0;
	v.par_symb = '$';
	bohr.push_back(v);

	int pattern_num;
	cin >> pattern_num;
	string pattern = "";
	for (int i = 0; i < pattern_num; i++) {
		cin >> pattern;
		patterns.push_back(pattern);
		add_string(pattern, i);
	}

	string text = "";
	cin >> text;

	int res_pos = 0;
	int u = 0;
	for (int i = 0; i < text.size(); i++) {
		res_pos = get_transition(res_pos, text[i] - 'a');
		u = res_pos;
		while (u != 0) {
			if (bohr[u].leaf) cout << i - patterns[bohr[u].pattern_num].length() + 2 << " " << patterns[bohr[u].pattern_num] << endl;
			u = get_good_suff_link(u);
		}
	}
	return 0;
}