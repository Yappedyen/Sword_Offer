#include"functions.h"


//Ϊ�˲���������б�¶�ּ�������־������������Ҫ����ĸ����ɵ����������˼��
//
//����һ�������(ransomNote) �ַ�����һ����־(magazine)�ַ������ж� ransomNote �ܲ����� magazines ������ַ����ɡ�
//
//������Թ��ɣ����� true �����򷵻� false ��
//
//magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�


bool canConstruct(string ransomNote, string magazine) {

    // unordered_map<char,int> m;

    // for(auto maga:magazine){
    //     m[maga]++;
    // }
    // for(auto note : ransomNote){
    //     m[note]--;
    // }

    // for(unordered_map<char,int>::iterator it = m.begin();it != m.end();it++){
    //     if(it->second <0){
    //         return false;
    //     }
    // }
    // return true;


    if (ransomNote.size() > magazine.size()) {
        return false;
    }

    vector<int> v(26);
    for (auto mag : magazine) {
        v[mag - 'a']++;
    }
    for (auto ran : ransomNote) {
        v[ran - 'a']--;
        if (v[ran - 'a'] < 0) {
            return false;
        }
    }
    return true;

    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    vector<int> cnt(26);
    for (auto& c : magazine) {
        cnt[c - 'a']++;
    }
    for (auto& c : ransomNote) {
        cnt[c - 'a']--;
        if (cnt[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}