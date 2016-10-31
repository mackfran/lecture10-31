void test_Attribute_setPoints() {
        Attribute att(4, 5);
        
        att.setPoints(0);
        if (att.getPoints() != 0) {
                cout << "bug in Attribute::setPoints()" << endl;
            }
        
        if (att.getIndex() != 4) {
                cout << "bug in Attribute::setPoints()" << endl;
            }
        
        att.setPoints(-1);
        if (att.getPoints() != -1) {
                cout << "bug in Attribute::setPoints()" << endl;
            }
        
        if (att.getIndex() != 4) {
                cout << "bug in Attribute::setPoints()" << endl;
            }
        
}

void test_Attribute_readwrite(){
        Attribute att;
        att.write(cout);
        cout << endl;
}


void test_Answer_construct(){
        Answer answer;
        Attribute attribute = answer.getAttribute();
        if (attribute.getPoints() != 0) {
                cout << "bug in Answer::Answer()" << endl;
            }
        
        if (attribute.getIndex() != 0) {
                cout << "bug in Answer::Answer()" << endl;
            }
        if (answer.getText() != ""){
                cout << "bug in Answer::Answer()" << endl;
            }
}


void test_Answer_setAttribute(){
        Attribute att;
        Attribute att1(1,2);
        Answer answer;
        
        
        answer.setAttribute(att);
        if (answer.getAttribute().getPoints() != 0) {
                cout << "bug in Answer::setAttribute()1" << endl;
            }
        
        if (answer.getAttribute().getIndex() != 0) {
                cout << "bug in Answer::setAttribute()2" << endl;
            }
    
        
        
        answer.setAttribute(att1);
        if ((answer.getAttribute()).getPoints() != 2) {
                cout << "bug in Answer::setAttribute()3" << endl;
            }
        
        if ((answer.getAttribute()).getIndex() != 1) {
                cout << "bug in Answer::setAttribute()4" << endl;
            }
    
}


void test_Answer_setText(){
        Answer answer;
        string a = "aaa";
        string b = "hello bob";
        
        answer.setText(a);
        if (answer.getText() != "aaa"){
                cout << "bug in Answer::setText()" << endl;
            }
        
        answer.setText(b);
        if (answer.getText() != "hello bob"){
                cout << "bug in Answer::setText()" << endl;
            }
        
    
}

void test_Answer_readwrite(){
        Answer answer;
        answer.write(cout);
}

void test_Personality(){
        Personality personality;
        Attribute att1( 5,5);
        
        personality.write(cout);
        personality.adjustPersonality(att1);
        personality.write(cout);
        personality.reset();
        personality.write(cout);
        
}

void test_Question_addAnswer(){
        Question ques;
        
        Attribute att(1, 5);
        string text1 = "bbb";
        Answer ans;
        ans.setAttribute(att);
        ans.setText(text1);
        
        Attribute att2(2, 4);
        string text2 = "abc";
        Answer ans2;
        ans2.setAttribute(att2);
        ans2.setText(text2);
        
        ques.addAnswer(ans);
        ques.addAnswer(ans2);
        ques.write(cout);
        
        
}

void test_Question_getNumAnswers(){
        Question ques;
        if (ques.getNumAnswers() != 0){
               cout << "bug in Question::getNumAnswers()" << endl;
            }
        Attribute att(1, 5);
        string text1 = "bbb";
        Answer ans;
        ans.setAttribute(att);
        ans.setText(text1);
        
        ques.addAnswer(ans);
        if (ques.getNumAnswers() != 1){
                cout << "bug in Question::getNumAnswers()" << endl;
            }
        
}
void test_Question_getAttributeOfAnswer(){
        Question ques;
        
        Attribute att(1, 5);
        string text1 = "bbb";
        Answer ans;
        ans.setAttribute(att);
        ans.setText(text1);
        ques.addAnswer(ans);
        
        if( ques.getAttributeOfAnswer(1).getIndex() != 1){
                cout << "bug in Question::getAttributeOfAnswer()" << endl;
            }
        if( ques.getAttributeOfAnswer(1).getPoints() != 5){
                cout << "bug in Question::getAttributeOfAnswer()" << endl;
            }
}



void test_Question_setQuestionPrompt(){
        Question ques;
        string text = "adgg";
        ques.setQuestionPrompt(text);
        cout << ques.getQuestionPrompt() << endl;