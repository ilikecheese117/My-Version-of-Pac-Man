#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("C++ Game Box");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	winState = new WinState();
	pauseState = new PauseState();
	chooseCharacterState = new ChooseCharacterState();
	chooseLevelState = new ChooseLevelState();
	// Initial State
	currentState = menuState;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu" && currentState->getMapChange()){
				gameState->createPlayArea(currentState->getPlayMap());
				gameState->setPlayMap(currentState->getPlayMap());
				if(currentState->getPlayMap() == "images/map4.png"){winState->setLvlSelect(3); }
				else if(currentState->getPlayMap() == "images/map3.png"){winState->setLvlSelect(2); }
				else if(currentState->getPlayMap() == "images/map2.png"){winState->setLvlSelect(1); }
				else if(currentState->getPlayMap() == "images/map1.png"){winState->setLvlSelect(0); }
				currentState = menuState;
			}else if(currentState->getNextState() == "Menu" && currentState->getChange()){
				gameState->getMap()->getPlayer()->loadSprite(currentState->getPlayerModel());
				gameState->setPlayerModel(currentState->getPlayerModel());
				menuState->createCharacter(currentState->getPlayerModel());
				currentState = menuState;
			}else if(currentState->getNextState() == "Menu" && pauseState->getQuit()){
				gameState->rebuild();
				currentState = menuState;
			}else if(currentState->getNextState() == "Win"){
				winState->setScore(gameState->getFinalScore());
				currentState = winState;
			}else if(currentState->getNextState() == "pause"){
				pauseState->setScore(gameState->getFinalScore());
				currentState = pauseState; 
			}else if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}else if(currentState->getNextState() == "Game"){
				if(currentState->goToNextLevel()){
					if(currentState->getLvlSelect() < 3){
						currentState->setLvlSelect(currentState->getLvlSelect()+1);
						winState->setPlayMap(currentState->getNextMap());
						gameState->createPlayArea(currentState->getNextMap());
						gameState->setPlayMap(currentState->getNextMap());
					}
					else{
						currentState->setLvlSelect(0);
						winState->setPlayMap(currentState->getNextMap());
						gameState->createPlayArea(currentState->getNextMap());
						gameState->setPlayMap(currentState->getNextMap());
					}
				}
				currentState = gameState;
			}else if(currentState->getNextState() == "over"){
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
			}else if(currentState->getNextState() == "Choose"){
				currentState = chooseCharacterState;
			}else if(currentState->getNextState() == "ChooseM"){
				currentState = chooseLevelState;
			}
			currentState -> reset();
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
} 

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
