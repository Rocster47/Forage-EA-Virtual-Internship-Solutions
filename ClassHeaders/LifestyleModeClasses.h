#ifndef LIFESTYLE_MODE_CLASSES_H
#define LIFESTYLE_MODE_CLASSES_H

#include <string>
#include <map>
#include <vector>

class Athlete;
class Coach;
class Team;
class Event;
class Person;

class Building {
private:
    std::string name;
    int maxCapacity;
    int currentCapacity;

public:
    std::string getName() const;
    void setName(const std::string& name);

    int getCurrentCapacity() const;
    void setCurrentCapacity(int currentCapacity);

    int getMaxCapacity() const;
    void setMaxCapacity(int maxCapacity);

    bool isFull() const;
};

class House : public Building {
private:
    int numBedrooms;
    std::vector<Person*> residents;

public:
    void hostParty();
    void addResident(Person* person);
    void removeResident(Person* person);
    std::vector<Person*> getResidents() const;
};

class Stadium : public Building {
private:
    Team* homeTeam;
    std::string nextMatch;

public:
    void setHomeTeam(Team* team);
    Team* getHomeTeam() const;

    void setNextMatch(const std::string& match);
    std::string getNextMatch() const;

    void startNextGame(const std::string& matchDetails);
};

class College : public Building {
public:
    void startLearning();
};

class TrainingGrounds : public Building {
public:
    void startTraining();
};

class Event {
private:
    std::string name;
    std::string description;

public:
    void setName(const std::string& name);
    std::string getName() const;

    void setDescription(const std::string& description);
    std::string getDescription() const;
};

class Schedule {
private:
    std::map<std::string, Event> events;

public:
    std::map<std::string, Event> getEvents() const;
    void setEvent(const std::string& key, const Event& event);
};

class Action {
private:
    std::string name;
    std::string description;

public:
    void setName(const std::string& name);
    std::string getName() const;

    void setDescription(const std::string& description);
    std::string getDescription() const;
};

class Person {
private:
    std::string name;
    int age;
    std::string mood;
    std::map<std::string, int> skills;
    std::string location;
    std::map<Person*, int> relationships;
    Schedule schedule;
    Building* building;
    std::vector<std::string> actions;

public:
    void setName(const std::string& name);
    std::string getName() const;

    void setAge(int age);
    int getAge() const;

    void setMood(const std::string& mood);
    std::string getMood() const;

    void setSkill(const std::string& skill, int level);
    int getSkill(const std::string& skill) const;

    void moveTo(const std::string& location);
    std::string getLocation() const;

    void setRelationship(Person* person, int value);
    int getRelationship(Person* person) const;

    void setSchedule(const std::string& timeSlot, const std::string& eventName);
    Schedule getSchedule() const;

    Building* getBuilding() const;

    void attend(const Event& event);
    void interactWith(Person& other);
    void rest();
};

class Athlete : public Person {
private:
    std::string position;
    float fatigue;
    float GPA;

public:
    std::string getPosition() const;
    void setPosition(const std::string& position);

    float getFatigue() const;
    void setFatigue(float fatigue);

    float getGPA() const;
    void setGPA(float GPA);

    void train(const std::string& trainingType);
    void playGame();
    void checkEligibility();
};

class Coach : public Person {
private:
    std::string strategyStyle;
    float leadershipScore;
    Team* team;

public:
    std::string getStrategyStyle() const;
    void setStrategyStyle(const std::string& strategyStyle);

    float getLeadershipScore() const;
    void setLeadershipScore(float leadershipScore);

    Team* getTeam() const;
    void setTeam(Team* team);

    void boostMorale();
    float evaluateAthlete(const Athlete& athlete);
    void trainAthlete(Athlete& athlete);
};

class Team {
private:
    Coach* coach;
    std::vector<Athlete> athletes;

public:
    void setCoach(Coach* coach);
    Coach* getCoach() const;

    void setAthletes(const std::vector<Athlete>& athletes);
    std::vector<Athlete> getAthletes() const;

    void addAthlete(const Athlete& athlete);
};

#endif
