#include<iostream>
#include<queue>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<vector>
using namespace std;

typedef int num;
typedef int sec;
typedef double minute;

//車子
struct Car{
  sec time_need;//加油需要的時間(3~6min)
  sec time_into_station;//這台車進到加油站的時間
  Car(){
    time_need= rand()%180+180;
    time_into_station=rand()%50400+0;
   }
};

//機台
struct Machine{
  long long int  accumulate_waiting_time;//把所有服務過的車的等待時間加起來
  minute avg_waiting_time;//來到這個機台加油的車子們_平均等待時間
  minute max_waiting_time;//來到這個機台加油的車子們_最大等待時間
  num count;//服務車數
  vector<sec> waiting_time;//等候時間
  queue<Car> wait;//等待中的車(0~5輛)
};



int main(){

  //每小時約有 [50,100] 輛車子來加油,則加油站營業時間為 7:00AM 到 9:00PM,約有[700,1400]輛車子來加油
  num N=rand()%700+700;//隨機產生今天來加油的總車數
  vector<Car> cars;
  for(int i=0;i<N;++i){
    cars.push_back( Car() ) ;
  }

  //一個等候車道和八個機台等候區
  queue<Car> gas_station_line;
  vector< Machine > machines;
  for(int id=1;id<=8;id++) machines.push_back(Machine());
  int time;
  long long int  total_time=0;//所有車子的等待時間總和
  num total_num=0;




  //while(1)輪循 營業時間 7:00AM 到 9:00PM
  while(1){


    //先看看有沒有在這個時間正好進到加油站的車
    for(int i=0;i<N;++i){
      if (cars[i].time_into_station == time) {
        gas_station_line.push(cars[i]);
      }
    }



    //任一機台有空
    while(machines[0].wait.size()<5 || machines[1].wait.size()<5 || machines[2].wait.size()<5 || machines[3].wait.size()<5 || machines[4].wait.size()<5 || machines[5].wait.size()<5 || machines[6].wait.size()<5 || machines[7].wait.size()<5  ){

      //找出車最少的機台
      int tmp_size=5,M;
      for(int i=0;i<8;++i){
        if(machines[i].wait.size()<tmp_size){
          tmp_size=machines[i].wait.size();
          M=i;
        }
      }
      //若等待車道上有車 最前面的那台開到機台上
      if(gas_station_line.empty()){
        break;
      }else{
        machines[M].wait.push( gas_station_line.front());
        gas_station_line.pop();
      }
    }




    //是否有車正好完成加油
    for(int i=0;i<8;++i){
      if(machines[i].wait.empty()){
      }else{
        --machines[i].wait.front().time_need;//正在加油
        //一台加完了
        if( machines[i].wait.front().time_need ==0 ){
          machines[i].waiting_time.push_back( time- machines[i].wait.front().time_into_station);
          machines[i].accumulate_waiting_time +=  (time- machines[i].wait.front().time_into_station);
          total_time += (time- machines[i].wait.front().time_into_station);
          machines[i].wait.pop();
          machines[i].count++;
          total_num++;
         }
      }
    }



    //計算結果
    minute station_avg;//一整天來這個加油站加油的車子們的平均等候時間
    minute station_max;//一整天來這個加油站加油的車子們的最長等候時間

    for(int i=0;i<8;++i){
      for(int j=0;j<machines[i].waiting_time.size();++j){
        if(machines[i].max_waiting_time<machines[i].waiting_time[j] ) machines[i].max_waiting_time=machines[i].waiting_time[j];
      }
      machines[i].avg_waiting_time= machines[i].accumulate_waiting_time/(machines[i].count *60.0);
      machines[i].max_waiting_time /= 60.0;
      if( station_max <machines[i].max_waiting_time ) station_max=machines[i].max_waiting_time;
    }
    station_avg=total_time/(total_num*60.0);

    //列印時間
    int second,hour,m;
    hour=(time/3600);
    m=(time-hour*3600)/60;
    second=time-hour*3600-m*60;
    if(time==50400) {
      cout<<"現在時間: "<<7+hour<<"點 "<<m<<"分 "<<second<< "秒"<<"      打烊囉~~~"<<endl;
    }else if(time>50400 && machines[0].wait.empty() && machines[1].wait.empty() && machines[2].wait.empty() && machines[3].wait.empty() && machines[4].wait.empty() && machines[5].wait.empty() && machines[6].wait.empty() && machines[7].wait.empty() ){
      cout<<"現在時間: "<<7+hour<<"點 "<<m<<"分 "<<second<< "秒"<<"   全部加完 下班囉~~~"<<endl;
      break;
    }else{
      cout<<"現在時間: "<<7+hour<<"點 "<<m<<"分 "<<second<< "秒"<<endl;
    }

    //列印結果
    cout<<"機台  "<<"服務車數   "<<"平均等候分鐘時間    "<<"最長等候分鐘時間"<<endl;
    for(int i=0;i<8;++i){
      cout<<i<<setw(12)<<machines[i].count<<setw(20)<<machines[i].avg_waiting_time<<setw(20)<<machines[i].max_waiting_time<<endl;
    }
    cout<<"整個加油站的平均等候時間: "<<station_avg;
    cout<<"       整個加油站的最長等候時間: "<<station_max<<endl;
    cout<<endl;






    //列印等待車道上和機台上有幾台車
    // for(int i=0;i<8;++i){
    //   cout<<"machines["<<i<<"] count="<<machines[i].count<<"wait.size()="<<machines[i].wait.size()<<endl;
    // }
    // cout<<"gas_station_line="<<gas_station_line.size()<<endl;
    // cout<<"check N="<<N<<endl;
    //
    //
    // cout<<"Time= "<<time<<endl;


    time++;
  }
  return 0;
}
