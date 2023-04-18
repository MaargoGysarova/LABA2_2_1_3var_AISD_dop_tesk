#include <iostream>
#include <cstdio>
#include <ctime>
#include "Tree_task.h"
#include <vector>

using namespace std;

void fill_vector(vector<int> &vec){
    int size;
    cout << "Enter the size of vector: ";
    cin >> size;
    int i=0;
    while(i<size){
        int tmp;
        cout << "Enter the element["<<i<<"] of vector: ";
        cin >> tmp;
        vec.push_back(tmp);
        i++;
    }
}

int check(){
    int m;
    while(!(cin >> m)){
        cin.clear();
        while(cin.get() != '\n');
        cout << "Error! Enter the number: ";
    }
    return m;
}

int menu() {
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - Create tree"<< endl;
    cout << "2 - Add new root"<< endl;
    cout << "3 - Delete root"<< endl;
    cout << "4 - Check existing root"<< endl;
    cout << "5 - Print tree" << endl;
    cout << "6 - Go out" << endl;
    int m2;
    m2 = check();
    return m2;
}
int lcg(){
    srand(time(NULL));
    int x;
    x = rand();
    return x;
}

template<typename T>
vector<int> task_T(std::vector<int> &vec){
    Tree_task1<T> tmp;
    std::vector<int> result;
    tmp.insert(tmp.return_root(),vec[0]);
    for(int i=1;i<vec.size();i++){
        if(tmp.contains(vec[i])){
            bool found = std::find(result.begin(), result.end(), vec[i]) != result.end();
            if(found){}
            else{
                result.push_back(vec[i]);
            }
        }
        else{
            tmp.insert(tmp.return_root(),vec[i]);
        }
    }
    return result;
}


//create tree
template<typename T>
void create_new_tree_T(Tree_task1<T> &tmp){
    int size_tree;
    int i=1;
    cout << "Enter the size of tree: ";
    cin >> size_tree;
    int key;
    cout << "Enter the key["<<i<<"]" << " of root: ";
    cin >> key;
    tmp.insert(tmp.return_root(),key);
    while(i<size_tree){
        cout << "Enter the key["<<i<< "]" << " of root: ";
        cin >> key;
        while(tmp.contains(key)){
            cout << "This key already exist. Enter another key: ";
            cin >> key;
        }
        tmp.insert(tmp.return_root(),key);
        i++;
    }

}

//add new root
template<typename T>
void add_root_T(Tree_task1<T> &tmp){
    int key;
    cout << "Enter the key of root: ";
    key = check();
    tmp.insert(tmp.return_root(),key);
}

//delete root
template<typename T>
void delete_root_T(Tree_task1<T> &tmp){
    int key;
    cout << "Enter the key of root: ";
    key = check();
    tmp.erase(key, tmp.return_root());
    while(tmp.contains(key)){
        tmp.erase_duplicate(key, tmp.return_root());
    }
}

//check existing root
template<typename T>
void check_root_T(Tree_task1<T> &tmp){
    int key;
    cout << "Enter the key of root: ";
    key = check();
    if(tmp.contains(key))
        cout << "This root exist" << endl;
    else
        cout << "This root not exist" << endl;
}

//print tree
template<typename T>
void print_tree_T(Tree_task1<T> &tmp){
    tmp.print_Tree(tmp.return_root(),3);
}



//создание дерева и заполнение его случ значениями
template<typename T>
void create_tree_T(Tree_task1<T> &tmp, int size_tree){
    int i =1;
    int key = lcg();
    tmp.insert(tmp.return_root(),key);
    while(i < size_tree){
        while(!tmp.contains(key)){key = lcg();}
        tmp.insert(tmp.return_root(),lcg());
        i++;
    }

}

template<typename T>
void insert_time_full_T(int size_tree){
    Tree_task1<T> tmp;
    clock_t start = clock();
    create_tree_T(tmp,size_tree);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    //запись в файл
    FILE *file;
    file = fopen("insert_time_full.txt", "a+");
    fprintf(file, "%d;%f\n", size_tree, seconds);
    fclose(file);
}

template<typename T>
void search_time_T(int size_tree){
    Tree_task1<T> tmp;
    create_tree_T(tmp,size_tree);

    int key = lcg();
    while (!tmp.contains(key)){key = lcg();}

    clock_t start = clock();
    tmp.contains(key);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    FILE *file;
    file = fopen("search_time.txt", "a+");
    fprintf(file, "%d;%f\n", size_tree, seconds);
    fclose(file);
}

template<typename T>
void insert_and_delete_time_T(int size_tree){
    Tree_task1<T> tmp;
    create_tree_T(tmp,size_tree);
    int key = lcg();
    while (tmp.contains(key)){key = lcg();}
    clock_t start = clock();
    tmp.insert(tmp.return_root(),key);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    FILE *file;
    file = fopen("insert_time.txt", "a+");
    fprintf(file, "%d %f\n", size_tree, seconds);
    fclose(file);

    while (!tmp.contains(key)){key = lcg();}
    start = clock();
    tmp.erase(key, tmp.return_root());
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    file = fopen("delete_time.txt", "a+");
    fprintf(file, "%d %f\n", size_tree, seconds);
    fclose(file);
}

template<typename T>
void create_file_T(int loop){
    if(loop==1) {
        insert_time_full_T<T>(1000);
        insert_time_full_T<T>(5000);
        insert_time_full_T<T>(10000);
        insert_time_full_T<T>(50000);
        insert_time_full_T<T>(100000);
    }
    if(loop==2) {
        search_time_T<T>(1000);
        search_time_T<T>(5000);
        search_time_T<T>(10000);
        search_time_T<T>(50000);
        search_time_T<T>(100000);
    }
    if(loop==3) {
        insert_and_delete_time_T<T>(1000);
        insert_and_delete_time_T<T>(5000);
        insert_and_delete_time_T<T>(10000);
        insert_and_delete_time_T<T>(50000);
        insert_and_delete_time_T<T>(100000);
    }
}


int main() {
    int loop;
    Tree_task1<int> tmp;
    cout << "Enter 1 to check task" << endl;
    cout << "Enter 2 to work with tree" << endl;
    cout << "Enter 3 to create txt file_time" << endl;
    cin >> loop;
    if (loop == 1) {
        vector<int> vec = {};
        fill_vector(vec);
        vector<int> result = task_T<int>(vec);
        for(int i : result){
            cout << i << " ";
        }
        return 0;
    }
    if (loop == 2) {
        int m1;
        while (true) {
            m1 = menu();
            switch (m1) {
                case 1:
                    create_new_tree_T(tmp);
                    break;
                case 2:
                    add_root_T(tmp);
                    break;
                case 3:
                    delete_root_T(tmp);
                    break;
                case 4:
                    check_root_T(tmp);
                    break;
                case 5:
                    print_tree_T(tmp);
                    break;
                case 6:
                    return 0;
                default:
                    cout << "Input correct value" << endl;
                    break;
            }
        }
    }
    if (loop == 3) {
        int loop1;
        cout << "Enter 1 to create file insert_time_full" << endl;
        cout << "Enter 2 to create file search_time" << endl;
        cout << "Enter 3 to create file insert_time and delete_time" << endl;
        cin >> loop1;
        create_file_T<int>(loop1);
    }
}

