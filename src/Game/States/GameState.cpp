#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	createPlayArea(getPlayMap());
	siren.load("music/ghost_sirens.wav");
	siren.setVolume(0.3f);
	power.load("music/power.wav");
	power.setVolume(0.3f);
	returning.load("music/returning.wav");
	returning.setVolume(0.3f);


}
void GameState::createPlayArea(string select){
	mapImage.load(select);
	map = MapBuilder().createMap(mapImage);
	map->getPlayer()->loadSprite(getPlayerModel());
}
void GameState::tick() {
	if(map->getPlayer()->getEntMan()->getAmountDots()% 100 == 0 && map->getPlayer()->getEntMan()->getAmountDots() != 0 && map->getPlayer()->getScore() != 0 && !map->getPlayer()->getEntMan()->getFruitMap()){
		map->addRandFruit();
	}
	if(map->getPlayer()->getEntMan()->getGhostsSize() < 4 && !returning.isPlaying()){
		power.stop();
		siren.stop();
		returning.play();
	}
	if(map->getPlayer()->getEntMan()->getGhostsSize() >= 4 && map->getPlayer()->getEntMan()->getKillable() && !power.isPlaying()){
		siren.stop();
		returning.stop();
		power.play();
	}
	else if(map->getPlayer()->getEntMan()->getKillable() == false && !siren.isPlaying()){
		power.stop();
		returning.stop();
		siren.play();
	}
	map->tick();
	if(map->getPlayer()->getEntMan()->getAmountDots() == 0){
		siren.stop();
		power.stop();
		returning.stop();
		setFinished(true);
		setNextState("Win");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
		rebuild();
	}
	if(map->getPlayer()->getHealth() == 0){
		siren.stop();
		power.stop();
		returning.stop();
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
		rebuild();
	}
	if(map->getPlayer()->getPause()){
		siren.stop();
		power.stop();
		returning.stop();
		setFinished(true);
		finalScore = map->getPlayer()->getScore();
		setNextState("pause");
		map->getPlayer()->setPause();
	}
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	siren.stop();
	power.stop();
	setFinished(false);
	setNextState("");
}
void GameState::rebuild(){
	map = MapBuilder().createMap(mapImage);
	map->getPlayer()->loadSprite(getPlayerModel());
}
int GameState::getFinalScore(){
	return finalScore;
}

Map* GameState::getMap(){
	return map;
}

GameState::~GameState(){
	delete map;
}