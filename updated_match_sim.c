void matchSim(Team team1,Team team2,char * date)
{
	int i ,r ,team1_goal_counter = 0 ,team2_goal_counter = 0;
	float team1_score_chance = teamAttack(team1) -  teamDefence(team2); //one of the parameters for team 1 score chance
	float team2_score_chance = teamAttack(team2) -  teamDefence(team1);
	if (team1_score_chance < 0)
		team1_score_chance = 0;
	if (team2_score_chance < 0)
		team2_score_chance = 0;
	for(i = 1 ; i <= 90 ; i++)	
	{
		r = rand() % 1000; // remember to put srand(time()); in main fucntion
		if ((team1_score_chance * 2 + 5) > (float) r)
		{
			team1_goal_counter++ ;
			//save the goal minute
		}
		r = rand() % 1000; // remember to put srand(time()); in main fucntion
		if ((team2_score_chance * 2 + 5) > (float) r)
		{
			team2_goal_counter++ ;
			//save the goal minute
		}
	}
	//team1 possession(team1,team2);
	//team2 possession(team2,team1);
	
	for (i = 0 ; i <= 10 ; i++) //fitness change
	{
		team1.fix_players[i].fitness = 0.95 * team1.fix_players[i].fitness;
		team2.fix_players[i].fitness = 0.95 * team2.fix_players[i].fitness;
	}
	if(team1_goal_counter > team2_goal_counter)
	{
		for (i = 0 ; i <= 10 ; i++) //fitness change
		{
		team1.fix_players[i].form = 1.05 * team1.fix_players[i].form;
		if (team1.fix_players[i].form > 100)
			team1.fix_players[i].form = 100;
		team2.fix_players[i].form = 0.95 * team2.fix_players[i].form;
		}
	}
	if(team1_goal_counter < team2_goal_counter)
	{
		for (i = 0 ; i <= 10 ; i++) //fitness change
		{
		team2.fix_players[i].form = 1.05 * team2.fix_players[i].form;
		if (team2.fix_players[i].form > 100)
			team2.fix_players[i].form = 100;
		team1.fix_players[i].form = 0.95 * team1.fix_players[i].form;
		}
	}
}
