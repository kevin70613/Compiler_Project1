                         Compiler HW1      F74009038  顧凱云

1. Environment : Linux 

2. Language : C++

3. Compile : g++ -o F74009038_HW1 F74009038.cpp

4. 執行 : ./F74009038_HW1 

5. 程式架構&解說 :

  (一) 程式架構 :
    這個程式包含:
     - 4個function如下:
        void errorCheck(string inputstr);   //用來判斷是否為error 
        void charDFA(string inputstr);   //用來判斷是否為char
        void numDFA(string inputstr);   //用來判斷是否為number
        void idDFA(string inputstr);   //用來判斷是否為identifier
     - 變數:
        state : 整個程式的中心概念就是一直讀next char直到發現 keyword,operator,
                  special symbols為止,在對已讀入的string做處理,每讀新的一行都會先設為0
                  當讀到keyword,operator,special symbols=> state 設為1(要做對應處理)
       
        front: 指向還未辨識的substirng的頭,當發現keyword, operator, special symbols後
                  做出對應處理,將front指到剩下還未被辨識的string的頭繼續
        
       length : 指向還未辨識的substring的尾巴(長度為length的substring),可作為從尾巴
                    往前取多少字元的依據 ,當辨識subtring後要更新front也會用到length協助
                    front = front+length 同時將length歸零 , 從新的string開始再慢慢讀
                    next char 增加length長度     
  
  (二)程式解說 :  
    (註 : 想詳細了解程式每個部分運作流程,程式碼解說已經寫在程式註解中 )
    整個程式的概念為將 main.c 中的內容一行行讀入 , 針對每一行讀入的string從第一個
    字元開始依序往後取得next char形成新的string ,依照形成string長度進入不同的case
    判斷(ex:當string長度為3時 , 可能包含 int , if , ==..等 , 但不可能含double) 不同的case
    對形成string從最後一個字元往前取substring進行判斷是否為:
     1.)  keywords   2) operator  3) special symbols
    
    同時對這個substring前面的string 丟進 四個 function進行判斷分別為:
     1. errorCheck : 判斷是否為用數字開頭的identifier
     2. charDFA : 判斷是否為char
     3. numDFA : 判斷是否為number
     4. idDFA : 判斷是否為identifier
    
    當找出keywords , operator , special symbols 後 (state 為  1),
    更新front ( front = front+length ) length 改成 0 之後 for loop length++變成1

    Ex:  double i1=3; 
           a. 這行 依序讀入next char後形成string" double" ,從最後一個e往前算6個取得
                substring "double" =>為<Keyword>,而前面的空白被忽略,更新front,
                length 繼續對剩餘的string作辨識
           b. 而取得string "i1="後 , 這個substring最後為 = 是<Operator>而前面 i1 經過
                idDFA function判斷為identifier
           c. 之後 string "3;" , 這個substring最後為 ; 是<Special>而前面的 3 經過numDFA
               function判斷為number
