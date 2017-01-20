float teamAttack(int team_num)
{
	float attack_overall ,mid_overall;
	switch(teams[team_num].formation)
	{
		case 1 ://4-4-2
			attack_overall = 0.5 * ( 0.5 * (teams[team_num].fix_players[9].skill + teams[team_num].fix_players[10].skill) + 0.3 * (teams[team_num].fix_players[9].form + teams[team_num].fix_players[10].form) + 0.2 * (teams[team_num].fix_players[9].fitness + teams[team_num].fix_players[10].fitness));
			mid_overall = 0.4 * (0.5 * ( 0.5 * (teams[team_num].fix_players[5].skill + teams[team_num].fix_players[6].skill) + 0.3 * (teams[team_num].fix_players[5].form + teams[team_num].fix_players[6].form) + 0.2 * (teams[team_num].fix_players[5].fitness + teams[team_num].fix_players[6].fitness))) + 0.6 * (0.5 * ( 0.5 * (teams[team_num].fix_players[7].skill + teams[team_num].fix_players[8].skill) + 0.3 * (teams[team_num].fix_players[7].form + teams[team_num].fix_players[8].form) + 0.2 * (teams[team_num].fix_players[7].fitness + teams[team_num].fix_players[8].fitness)));
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;
		case 2 ://4-3-3
			attack_overall = ( 0.5 * (teams[team_num].fix_players[9].skill + teams[team_num].fix_players[10].skill + teams[team_num].fix_players[8].skill) + 0.3 * (teams[team_num].fix_players[8].form + teams[team_num].fix_players[9].form + teams[team_num].fix_players[10].form) + 0.2 * (teams[team_num].fix_players[8].fitness + teams[team_num].fix_players[9].fitness + teams[team_num].fix_players[10].fitness)) / 3; 
			mid_overall = ( 0.5 * (teams[team_num].fix_players[5].skill + teams[team_num].fix_players[6].skill + teams[team_num].fix_players[7].skill) + 0.3 * (teams[team_num].fix_players[5].form + teams[team_num].fix_players[6].form + teams[team_num].fix_players[7].form) + 0.2 * (teams[team_num].fix_players[5].fitness + teams[team_num].fix_players[6].fitness + teams[team_num].fix_players[7].fitness)) / 3; 
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;
		case 3 ://5-4-1
			attack_overall = 0.5 * teams[team_num].fix_players[10].skill + 0.3 * teams[team_num].fix_players[10].form + 0.2 * teams[team_num].fix_players[10].fitness;
			mid_overall = 0.4 * (0.5 * ( 0.5 * (teams[team_num].fix_players[7].skill + teams[team_num].fix_players[6].skill) + 0.3 * (teams[team_num].fix_players[7].form + teams[team_num].fix_players[6].form) + 0.2 * (teams[team_num].fix_players[7].fitness + teams[team_num].fix_players[6].fitness))) + 0.6 * (0.5 * ( 0.5 * (teams[team_num].fix_players[8].skill + teams[team_num].fix_players[9].skill) + 0.3 * (teams[team_num].fix_players[9].form + teams[team_num].fix_players[8].form) + 0.2 * (teams[team_num].fix_players[9].fitness + teams[team_num].fix_players[8].fitness)));
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;
		case 4 ://3-5-2
			attack_overall = 0.5 * ( 0.5 * (teams[team_num].fix_players[9].skill + teams[team_num].fix_players[10].skill) + 0.3 * (teams[team_num].fix_players[9].form + teams[team_num].fix_players[10].form) + 0.2 * (teams[team_num].fix_players[9].fitness + teams[team_num].fix_players[10].fitness));
			mid_overall = 0.2 * ( 0.5 * (teams[team_num].fix_players[4].skill + teams[team_num].fix_players[5].skill + teams[team_num].fix_players[6].skill + teams[team_num].fix_players[7].skill + teams[team_num].fix_players[8].skill) + 0.3 * (teams[team_num].fix_players[4].form + teams[team_num].fix_players[5].form + teams[team_num].fix_players[6].form + teams[team_num].fix_players[7].form + teams[team_num].fix_players[8].form) + 0.2 * (teams[team_num].fix_players[4].fitness + teams[team_num].fix_players[5].fitness + teams[team_num].fix_players[6].fitness + teams[team_num].fix_players[7].fitness + teams[team_num].fix_players[8].fitness));
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;	
	}
}
float teamDefence(int team_num)
{
	float defence_overall ,mid_overall ,goalkeeper_overall;
	goalkeeper_overall = 0.5 * teams[team_num].fix_players[0].skill + 0.3 * teams[team_num].fix_players[0].form + 0.2 * teams[team_num].fix_players[0].fitness;
	switch(teams[team_num].formation)
	{
		case 1 ://4-4-2
			defence_overall = 0.25 * ( 0.5 * (teams[team_num].fix_players[1].skill + teams[team_num].fix_players[2].skill + teams[team_num].fix_players[3].skill + teams[team_num].fix_players[4].skill) + 0.3 * (teams[team_num].fix_players[1].form + teams[team_num].fix_players[2].form + teams[team_num].fix_players[3].form + teams[team_num].fix_players[4].form) + 0.2 * (teams[team_num].fix_players[1].fitness + teams[team_num].fix_players[2].fitness + teams[team_num].fix_players[3].fitness + teams[team_num].fix_players[4].fitness));
			mid_overall = 0.8 * (0.5 * ( 0.5 * (teams[team_num].fix_players[5].skill + teams[team_num].fix_players[6].skill) + 0.2 * (teams[team_num].fix_players[5].form + teams[team_num].fix_players[6].form) + 0.2 * (teams[team_num].fix_players[5].fitness + teams[team_num].fix_players[6].fitness))) + 0.6 * (0.5 * ( 0.5 * (teams[team_num].fix_players[7].skill + teams[team_num].fix_players[8].skill) + 0.3 * (teams[team_num].fix_players[7].form + teams[team_num].fix_players[8].form) + 0.2 * (teams[team_num].fix_players[7].fitness + teams[team_num].fix_players[8].fitness)));
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;
		case 2 ://4-3-3
			defence_overall = 0.25 * ( 0.5 * (teams[team_num].fix_players[1].skill + teams[team_num].fix_players[2].skill + teams[team_num].fix_players[3].skill + teams[team_num].fix_players[4].skill) + 0.3 * (teams[team_num].fix_players[1].form + teams[team_num].fix_players[2].form + teams[team_num].fix_players[3].form + teams[team_num].fix_players[4].form) + 0.2 * (teams[team_num].fix_players[1].fitness + teams[team_num].fix_players[2].fitness + teams[team_num].fix_players[3].fitness + teams[team_num].fix_players[4].fitness));
			mid_overall = ( 0.5 * (teams[team_num].fix_players[5].skill + teams[team_num].fix_players[6].skill + teams[team_num].fix_players[7].skill) + 0.3 * (teams[team_num].fix_players[5].form + teams[team_num].fix_players[6].form + teams[team_num].fix_players[7].form) + 0.2 * (teams[team_num].fix_players[5].fitness + teams[team_num].fix_players[6].fitness + teams[team_num].fix_players[7].fitness)) / 3; 
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;
		case 3 ://5-4-1
			defence_overall = 0.2 * ( 0.5 * (teams[team_num].fix_players[1].skill + teams[team_num].fix_players[2].skill + teams[team_num].fix_players[3].skill + teams[team_num].fix_players[4].skill + teams[team_num].fix_players[5].skill) + 0.3 * (teams[team_num].fix_players[1].form + teams[team_num].fix_players[2].form + teams[team_num].fix_players[3].form + teams[team_num].fix_players[4].form + teams[team_num].fix_players[5].form) + 0.2 * (teams[team_num].fix_players[1].fitness + teams[team_num].fix_players[2].fitness + teams[team_num].fix_players[3].fitness + teams[team_num].fix_players[4].fitness + teams[team_num].fix_players[5].fitness));
			mid_overall = 0.7 * (0.5 * ( 0.5 * (teams[team_num].fix_players[7].skill + teams[team_num].fix_players[6].skill) + 0.3 * (teams[team_num].fix_players[7].form + teams[team_num].fix_players[6].form) + 0.2 * (teams[team_num].fix_players[7].fitness + teams[team_num].fix_players[6].fitness))) + 0.3 * (0.5 * ( 0.5 * (teams[team_num].fix_players[8].skill + teams[team_num].fix_players[9].skill) + 0.3 * (teams[team_num].fix_players[9].form + teams[team_num].fix_players[8].form) + 0.2 * (teams[team_num].fix_players[9].fitness + teams[team_num].fix_players[8].fitness)));
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;
		case 4 ://3-5-2
			defence_overall = ( 0.5 * (teams[team_num].fix_players[1].skill + teams[team_num].fix_players[2].skill + teams[team_num].fix_players[3].skill) + 0.3 * (teams[team_num].fix_players[1].form + teams[team_num].fix_players[2].form + teams[team_num].fix_players[3].form) + 0.2 * (teams[team_num].fix_players[1].fitness + teams[team_num].fix_players[2].fitness + teams[team_num].fix_players[3].fitness)) / 3; 
			mid_overall = 0.2 * ( 0.5 * (teams[team_num].fix_players[4].skill + teams[team_num].fix_players[5].skill + teams[team_num].fix_players[6].skill + teams[team_num].fix_players[7].skill + teams[team_num].fix_players[8].skill) + 0.3 * (teams[team_num].fix_players[4].form + teams[team_num].fix_players[5].form + teams[team_num].fix_players[6].form + teams[team_num].fix_players[7].form + teams[team_num].fix_players[8].form) + 0.2 * (teams[team_num].fix_players[4].fitness + teams[team_num].fix_players[5].fitness + teams[team_num].fix_players[6].fitness + teams[team_num].fix_players[7].fitness + teams[team_num].fix_players[8].fitness));
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;	
	}
}
int possession(Team team1,Team team2)
{
	float mid1_overall ,mid2_overall;
	switch(team1.formation)
	{
		case 1 ://4-4-2
			mid1_overall = 0.5 * (0.5 * ( 0.5 * (team1.fix_players[5].skill + team1.fix_players[6].skill) + 0.5 * (team1.fix_players[5].form + team1.fix_players[6].form) + 0.2 * (team1.fix_players[5].fitness + team1.fix_players[6].fitness))) + 0.6 * (0.5 * ( 0.5 * (team1.fix_players[7].skill + team1.fix_players[8].skill) + 0.3 * (team1.fix_players[7].form + team1.fix_players[8].form) + 0.2 * (team1.fix_players[7].fitness + team1.fix_players[8].fitness)));
			break;
		case 2 ://4-3-3
			mid1_overall = ( 0.5 * (team1.fix_players[5].skill + team1.fix_players[6].skill + team1.fix_players[7].skill) + 0.3 * (team1.fix_players[5].form + team1.fix_players[6].form + team1.fix_players[7].form) + 0.2 * (team1.fix_players[5].fitness + team1.fix_players[6].fitness + team1.fix_players[7].fitness)) / 3; 
			break;
		case 3 ://5-4-1
			mid1_overall = 0.5 * (0.5 * ( 0.5 * (team1.fix_players[7].skill + team1.fix_players[6].skill) + 0.3 * (team1.fix_players[7].form + team1.fix_players[6].form) + 0.2 * (team1.fix_players[7].fitness + team1.fix_players[6].fitness))) + 0.5 * (0.5 * ( 0.5 * (team1.fix_players[8].skill + team1.fix_players[9].skill) + 0.3 * (team1.fix_players[9].form + team1.fix_players[8].form) + 0.2 * (team1.fix_players[9].fitness + team1.fix_players[8].fitness)));
			break;
		case 4 ://3-5-2
			mid1_overall = 0.2 * ( 0.5 * (team1.fix_players[4].skill + team1.fix_players[5].skill + team1.fix_players[6].skill + team1.fix_players[7].skill + team1.fix_players[8].skill) + 0.3 * (team1.fix_players[4].form + team1.fix_players[5].form + team1.fix_players[6].form + team1.fix_players[7].form + team1.fix_players[8].form) + 0.2 * (team1.fix_players[4].fitness + team1.fix_players[5].fitness + team1.fix_players[6].fitness + team1.fix_players[7].fitness + team1.fix_players[8].fitness));
			break;	
	}
	switch(team2.formation)
	{
		case 1 ://4-4-2
			mid2_overall = 0.5 * (0.5 * ( 0.5 * (team2.fix_players[5].skill + team2.fix_players[6].skill) + 0.5 * (team2.fix_players[5].form + team2.fix_players[6].form) + 0.2 * (team2.fix_players[5].fitness + team2.fix_players[6].fitness))) + 0.6 * (0.5 * ( 0.5 * (team2.fix_players[7].skill + team2.fix_players[8].skill) + 0.3 * (team2.fix_players[7].form + team2.fix_players[8].form) + 0.2 * (team2.fix_players[7].fitness + team2.fix_players[8].fitness)));
			break;
		case 2 ://4-3-3
			mid2_overall = ( 0.5 * (team2.fix_players[5].skill + team2.fix_players[6].skill + team2.fix_players[7].skill) + 0.3 * (team2.fix_players[5].form + team2.fix_players[6].form + team2.fix_players[7].form) + 0.2 * (team2.fix_players[5].fitness + team2.fix_players[6].fitness + team2.fix_players[7].fitness)) / 3; 
			break;
		case 3 ://5-4-1
			mid2_overall = 0.5 * (0.5 * ( 0.5 * (team2.fix_players[7].skill + team2.fix_players[6].skill) + 0.3 * (team2.fix_players[7].form + team2.fix_players[6].form) + 0.2 * (team2.fix_players[7].fitness + team2.fix_players[6].fitness))) + 0.5 * (0.5 * ( 0.5 * (team2.fix_players[8].skill + team2.fix_players[9].skill) + 0.3 * (team2.fix_players[9].form + team2.fix_players[8].form) + 0.2 * (team2.fix_players[9].fitness + team2.fix_players[8].fitness)));
			break;
		case 4 ://3-5-2
			mid2_overall = 0.2 * ( 0.5 * (team2.fix_players[4].skill + team2.fix_players[5].skill + team2.fix_players[6].skill + team2.fix_players[7].skill + team2.fix_players[8].skill) + 0.3 * (team2.fix_players[4].form + team2.fix_players[5].form + team2.fix_players[6].form + team2.fix_players[7].form + team2.fix_players[8].form) + 0.2 * (team2.fix_players[4].fitness + team2.fix_players[5].fitness + team2.fix_players[6].fitness + team2.fix_players[7].fitness + team2.fix_players[8].fitness));
			break;	
	}
	return (50 - (mid1_overall - mid2_overall) / 2);
}
void matchSim(int team1_num,int team2_num)
{
	int i ,r ,team1_goal_counter = 0 ,team2_goal_counter = 0;
	float team1_score_chance = teamAttack(team1_num) -  teamDefence(team2_num); //one of the parameters for team 1 score chance
	float team2_score_chance = teamAttack(team2_num) -  teamDefence(team1_num);
	if (team1_score_chance < 0)
		team1_score_chance = 0;
	if (team2_score_chance < 0)
		team2_score_chance = 0;
	for(i = 1 ; i <= 90 ; i++)	
	{
		r = rand() % 1000; // remember to put srand(time()); in main function
		if ((team1_score_chance * 2 + 5) > (float) r)
		{
			team1_goal_counter++ ;
			//save the goal minute
		}
		r = rand() % 1000; // remember to put srand(time()); in main function
		if ((team2_score_chance * 2 + 5) > (float) r)
		{
			team2_goal_counter++ ;
			//save the goal minute
		}
	}
	//team1 possession(team1,team2);
	//team2 possession(team2,team1);
	teams[team1_num].goals_for += team1_goal_counter;
	teams[team1_num].goals_against += team2_goal_counter;
	teams[team2_num].goals_for += team2_goal_counter;
	teams[team2_num].goals_against += team1_goal_counter;
	if(team1_goal_counter > team2_goal_counter)
	{
		teams[team1_num].points += 3;
		teams[team1_num].win += 1;
		teams[team2_num].lose += 1;
	}
	if(team1_goal_counter < team2_goal_counter)
	{
		teams[team2_num].points += 3;
		teams[team2_num].win += 1;
		teams[team1_num].lose += 1;
	}
	if(team1_goal_counter = team2_goal_counter)
	{
		teams[team1_num].points += 1;
		teams[team2_num].points += 1;
		teams[team1_num].draw += 1;
		teams[team2_num].draw += 1;
	}	
}
