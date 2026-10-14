#include <iostream>
//#include <vector>
//#include <cmath>
/*
int main(){
    char name[100];
    std::cout<<"Please enter your name:";
    std::cin>>name;
    std::cout<<"Hello,"<<name<<"!";
    return 0;
}
*/
/*
int main(){
    float temp;
    int minute;
    std::cout<<"请输入你的体温：";
    std::cin>>temp;
    std::cout<<"你上次喝水是几分钟前：";
    std::cin>>minute;
    if(temp<35.0){
        std::cout<<"体温错误！";
    }else if(temp>37.5){
        std::cout<<"体温过高，喝水休息！";
    }
    else{
        if(minute>60){
            std::cout<<"也该喝水了！";
        }
        else{
            std::cout<<"状态良好！";
        }
    }
}
*/
/*
int main(){
    std::cout<<"start!输入：";
    int a;
    std::cin>>a;
    while(a<0){
        a=a+1;
    }
    return 0;
}

int main(){
    int a;
    std::cout<<"start!输入：";
    std::cin>>a;
    do{
        a=a+1;
    }while(a<0);
}
*/
//体现三思后行与先斩后奏的区别，当输入本身已为正时
/*
int main() {
    double temps[5] = {23.5, 24.1, 22.8, 25.0, 23.9};
    
    printf("数组 temps 的起始地址: %p\n", (void*)&temps[0]);
    printf("\n");
    
    for (int i = 0; i < 5; ++i) {
        printf("temps[%d] 的值是 %.1f，地址是 %p\n", 
               i, temps[i], (void*)&temps[i]);
    }
    
    return 0;
}
*/
/*
int main(){
    std::vector<int> v;
    int putin;
    std::cout<<"输入你要储存的数据：";
    while(std::cin>>putin && putin!=-1){
        v.push_back(putin);
    }
    for(int x : v){
        std::cout<<x<<" ";
    }
}
*/
/*
int main(){
    int arr[100];
    int num;
//    bool swap=false;
    do{
        std::cout<<"共输入几个数字？";
        std::cin>>num;
        if(num<=0 || num>100) std::cout<<"内容异常，重新输入"<<std::endl;
    }while(num<=0 || num>100);
    
//    if (num>100) {
//        std::cout<<"内容过多，重新输入";
//        return 0;
//    }
    for (int i = 0;i < num;i++){
        std::cout<<"第"<<i+1<<"个数字：";
        std::cin>>arr[i];
        }
    for (int j = 0;j < num-1;j++){
        bool swap=false;
        for (int k = 0;k < num-1-j;k++){
            if(arr[k]<arr[k+1]){
                int middle = arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=middle;
                swap = true;
            }
        }
        if (!swap){
            break;
        }
        

    }
    for (int i =0;i < num;i++){
        std::cout<<arr[i]<<",";
    }
}
*/
using namespace std;

const int MAX = 100;

// 交换工具函数（若使用快速排序，可保留）
void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}//哈哈，最后手动交换了，一次没用上：<
/* ---- 在此实现你的排序函数 ---- */
// 例如：int partition(...) 与 void quick_sort(...)
// 或者：void merge(...) 与 void merge_sort_rec(...) 和 void merge_sort(...)
int partition(int arr[],int low, int high){
    int i = low-1;
    int vari;
    for (int j = low;j < high;j++ ){
        if (arr[j]<=arr[high]){
            i++;
            vari = arr[i];
            arr[i]=arr[j];
            arr[j]=vari;            
        }
    }
    //swap(arr[i+1],arr[high]);
    return i+1;
}
void quick_sort(int arr[], int low, int high){
    if(low >= high) return;
    int mid = partition(arr, low, high);
    int vari2 = arr[high];
    arr[high]=arr[mid];
    arr[mid]=vari2;
    quick_sort(arr, low, mid-1);
    quick_sort(arr, mid+1, high);
    

}

/* ---- 递归二分查找 ---- */
int binary_search_rec(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (target < arr[mid])
        return binary_search_rec(arr, left, mid - 1, target);
    else
        return binary_search_rec(arr, mid + 1, right, target);
}

/* ---- 工具函数 ---- */
void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int data[MAX];
    int n;

    cout << "🎵 AI音乐推荐 - 搜索排序引擎 🎵" << endl;
    cout << "=================================" << endl;
    cout << "请输入歌曲数量 (1~" << MAX << "): ";
    cin >> n;
    if (n < 1 || n > MAX) {
        cout << "数量不合法，程序退出。" << endl;
        return 1;
    }
    cout << "请输入 " << n << " 首歌曲的推荐优先级分数（整数）：" << endl;
    for (int i = 0; i < n; ++i) cin >> data[i];

    cout << "\n原始分数序列：";
    print_array(data, n);

    // 调用你选择的排序函数
    quick_sort(data, 0, n - 1);   // 如果用快排
    // 或 merge_sort(data, n);       // 如果用归并

    cout << "排序后分数序列：";
    print_array(data, n);

    char again;
    do {
        int target;
        cout << "\n请输入要查询的分数：";
        cin >> target;
        int idx = binary_search_rec(data, 0, n - 1, target);
        if (idx != -1)
            cout << "✅ 命中！分数 " << target << " 在索引 " << idx
                 << " (推荐优先级从低到高排列)" << endl;
        else
            cout << "❌ 未找到分数 " << target << "，可能未包含在歌单中。" << endl;
        cout << "是否继续查询？(y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "引擎关闭，感谢使用AI音乐推荐系统！" << endl;
    return 0;
}