                         Compiler HW1      F74009038  �U�ͤ�

1. Environment : Linux 

2. Language : C++

3. Compile : g++ -o F74009038_HW1 F74009038.cpp

4. ���� : ./F74009038_HW1 

5. �{���[�c&�ѻ� :

  (�@) �{���[�c :
    �o�ӵ{���]�t:
     - 4��function�p�U:
        void errorCheck(string inputstr);   //�ΨӧP�_�O�_��error 
        void charDFA(string inputstr);   //�ΨӧP�_�O�_��char
        void numDFA(string inputstr);   //�ΨӧP�_�O�_��number
        void idDFA(string inputstr);   //�ΨӧP�_�O�_��identifier
     - �ܼ�:
        state : ��ӵ{�������߷����N�O�@��Ūnext char����o�{ keyword,operator,
                  special symbols����,�b��wŪ�J��string���B�z,�CŪ�s���@�泣�|���]��0
                  ��Ū��keyword,operator,special symbols=> state �]��1(�n�������B�z)
       
        front: ���V�٥����Ѫ�substirng���Y,��o�{keyword, operator, special symbols��
                  ���X�����B�z,�Nfront����ѤU�٥��Q���Ѫ�string���Y�~��
        
       length : ���V�٥����Ѫ�substring������(���׬�length��substring),�i�@���q����
                    ���e���h�֦r�����̾� ,�����subtring��n��sfront�]�|�Ψ�length��U
                    front = front+length �P�ɱNlength�k�s , �q�s��string�}�l�A�C�CŪ
                    next char �W�[length����     
  
  (�G)�{���ѻ� :  
    (�� : �Q�ԲӤF�ѵ{���C�ӳ����B�@�y�{,�{���X�ѻ��w�g�g�b�{�����Ѥ� )
    ��ӵ{�����������N main.c �������e�@���Ū�J , �w��C�@��Ū�J��string�q�Ĥ@��
    �r���}�l�̧ǩ�����onext char�Φ��s��string ,�̷ӧΦ�string���׶i�J���P��case
    �P�_(ex:��string���׬�3�� , �i��]�t int , if , ==..�� , �����i��tdouble) ���P��case
    ��Φ�string�q�̫�@�Ӧr�����e��substring�i��P�_�O�_��:
     1.)  keywords   2) operator  3) special symbols
    
    �P�ɹ�o��substring�e����string ��i �|�� function�i��P�_���O��:
     1. errorCheck : �P�_�O�_���μƦr�}�Y��identifier
     2. charDFA : �P�_�O�_��char
     3. numDFA : �P�_�O�_��number
     4. idDFA : �P�_�O�_��identifier
    
    ���Xkeywords , operator , special symbols �� (state ��  1),
    ��sfront ( front = front+length ) length �令 0 ���� for loop length++�ܦ�1

    Ex:  double i1=3; 
           a. �o�� �̧�Ū�Jnext char��Φ�string" double" ,�q�̫�@��e���e��6�Ө��o
                substring "double" =>��<Keyword>,�ӫe�����ťճQ����,��sfront,
                length �~���Ѿl��string�@����
           b. �Ө��ostring "i1="�� , �o��substring�̫ᬰ = �O<Operator>�ӫe�� i1 �g�L
                idDFA function�P�_��identifier
           c. ���� string "3;" , �o��substring�̫ᬰ ; �O<Special>�ӫe���� 3 �g�LnumDFA
               function�P�_��number
