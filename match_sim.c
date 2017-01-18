float teamAttack(Team current_team)
{
	float attack_overall ,mid_overall;
	switch(current_team.formation)
	{
		case 1 ://4-4-2
			attack_overall = 0.5 * ( 0.5 * (current_team.fix_players[10].skill + current_team.fix_players[11].skill) + 0.3 * (current_team.fix_players[10].form + current_team.fix_players[11].form) + 0.2 * (current_team.fix_players[10].fitness + current_team.fix_players[11].fitness));
			mid_overall = 0.4 * (0.5 * ( 0.5 * (current_team.fix_players[6].skill + current_team.fix_players[7].skill) + 0.3 * (current_team.fix_players[6].form + current_team.fix_players[7].form) + 0.2 * (current_team.fix_players[6].fitness + current_team.fix_players[7].fitness))) + 0.6 * (0.5 * ( 0.5 * (current_team.fix_players[8].skill + current_team.fix_players[9].skill) + 0.3 * (current_team.fix_players[8].form + current_team.fix_players[9].form) + 0.2 * (current_team.fix_players[8].fitness + current_team.fix_players[9].fitness)));
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;
		case 2 ://4-3-3
			attack_overall = ( 0.5 * (current_team.fix_players[10].skill + current_team.fix_players[11].skill + current_team.fix_players[9].skill) + 0.3 * (current_team.fix_players[9].form + current_team.fix_players[10].form + current_team.fix_players[11].form) + 0.2 * (current_team.fix_players[9].fitness + current_team.fix_players[10].fitness + current_team.fix_players[11].fitness)) / 3; 
			mid_overall = ( 0.5 * (current_team.fix_players[6].skill + current_team.fix_players[7].skill + current_team.fix_players[8].skill) + 0.3 * (current_team.fix_players[6].form + current_team.fix_players[7].form + current_team.fix_players[8].form) + 0.2 * (current_team.fix_players[6].fitness + current_team.fix_players[7].fitness + current_team.fix_players[8].fitness)) / 3; 
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;
		case 3 ://5-4-1
			attack_overall = 0.5 * current_team.fix_players[11].skill + 0.3 * current_team.fix_players[11].form + 0.2 * current_team.fix_players[11].fitness;
			mid_overall = 0.4 * (0.5 * ( 0.5 * (current_team.fix_players[8].skill + current_team.fix_players[7].skill) + 0.3 * (current_team.fix_players[8].form + current_team.fix_players[7].form) + 0.2 * (current_team.fix_players[8].fitness + current_team.fix_players[7].fitness))) + 0.6 * (0.5 * ( 0.5 * (current_team.fix_players[9].skill + current_team.fix_players[10].skill) + 0.3 * (current_team.fix_players[10].form + current_team.fix_players[9].form) + 0.2 * (current_team.fix_players[10].fitness + current_team.fix_players[9].fitness)));
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;
		case 4 ://3-5-2
			attack_overall = 0.5 * ( 0.5 * (current_team.fix_players[10].skill + current_team.fix_players[11].skill) + 0.3 * (current_team.fix_players[10].form + current_team.fix_players[11].form) + 0.2 * (current_team.fix_players[10].fitness + current_team.fix_players[11].fitness));
			mid_overall = 0.2 * ( 0.5 * (current_team.fix_players[5].skill + current_team.fix_players[6].skill + current_team.fix_players[7].skill + current_team.fix_players[8].skill + current_team.fix_players[9].skill) + 0.3 * (current_team.fix_players[5].form + current_team.fix_players[6].form + current_team.fix_players[7].form + current_team.fix_players[8].form + current_team.fix_players[9].form) + 0.2 * (current_team.fix_players[5].fitness + current_team.fix_players[6].fitness + current_team.fix_players[7].fitness + current_team.fix_players[8].fitness + current_team.fix_players[9].fitness));
			return (0.6 * attack_overall + 0.4 * mid_overall);
			break;	
	}
}
float teamDefence(Team current_team)
{
	float defence_overall ,mid_overall ,goalkeeper_overall;
	goalkeeper_overall = 0.5 * current_team.fix_players[1].skill + 0.3 * current_team.fix_players[1].form + 0.2 * current_team.fix_players[1].fitness;
	switch(current_team.formation)
	{
		case 1 ://4-4-2
			defence_overall = 0.25 * ( 0.5 * (current_team.fix_players[2].skill + current_team.fix_players[3].skill + current_team.fix_players[4].skill + current_team.fix_players[5].skill) + 0.3 * (current_team.fix_players[2].form + current_team.fix_players[3].form + current_team.fix_players[4].form + current_team.fix_players[5].form) + 0.2 * (current_team.fix_players[2].fitness + current_team.fix_players[3].fitness + current_team.fix_players[4].fitness + current_team.fix_players[5].fitness));
			mid_overall = 0.8 * (0.5 * ( 0.5 * (current_team.fix_players[6].skill + current_team.fix_players[7].skill) + 0.2 * (current_team.fix_players[6].form + current_team.fix_players[7].form) + 0.2 * (current_team.fix_players[6].fitness + current_team.fix_players[7].fitness))) + 0.6 * (0.5 * ( 0.5 * (current_team.fix_players[8].skill + current_team.fix_players[9].skill) + 0.3 * (current_team.fix_players[8].form + current_team.fix_players[9].form) + 0.2 * (current_team.fix_players[8].fitness + current_team.fix_players[9].fitness)));
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;
		case 2 ://4-3-3
			defence_overall = 0.25 * ( 0.5 * (current_team.fix_players[2].skill + current_team.fix_players[3].skill + current_team.fix_players[4].skill + current_team.fix_players[5].skill) + 0.3 * (current_team.fix_players[2].form + current_team.fix_players[3].form + current_team.fix_players[4].form + current_team.fix_players[5].form) + 0.2 * (current_team.fix_players[2].fitness + current_team.fix_players[3].fitness + current_team.fix_players[4].fitness + current_team.fix_players[5].fitness));
			mid_overall = ( 0.5 * (current_team.fix_players[6].skill + current_team.fix_players[7].skill + current_team.fix_players[8].skill) + 0.3 * (current_team.fix_players[6].form + current_team.fix_players[7].form + current_team.fix_players[8].form) + 0.2 * (current_team.fix_players[6].fitness + current_team.fix_players[7].fitness + current_team.fix_players[8].fitness)) / 3; 
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;
		case 3 ://5-4-1
			defence_overall = 0.2 * ( 0.5 * (current_team.fix_players[2].skill + current_team.fix_players[3].skill + current_team.fix_players[4].skill + current_team.fix_players[5].skill + current_team.fix_players[6].skill) + 0.3 * (current_team.fix_players[2].form + current_team.fix_players[3].form + current_team.fix_players[4].form + current_team.fix_players[5].form + current_team.fix_players[6].form) + 0.2 * (current_team.fix_players[2].fitness + current_team.fix_players[3].fitness + current_team.fix_players[4].fitness + current_team.fix_players[5].fitness + current_team.fix_players[6].fitness));
			mid_overall = 0.7 * (0.5 * ( 0.5 * (current_team.fix_players[8].skill + current_team.fix_players[7].skill) + 0.3 * (current_team.fix_players[8].form + current_team.fix_players[7].form) + 0.2 * (current_team.fix_players[8].fitness + current_team.fix_players[7].fitness))) + 0.3 * (0.5 * ( 0.5 * (current_team.fix_players[9].skill + current_team.fix_players[10].skill) + 0.3 * (current_team.fix_players[10].form + current_team.fix_players[9].form) + 0.2 * (current_team.fix_players[10].fitness + current_team.fix_players[9].fitness)));
			return (0.5 * defence_overall + 0.3 * mid_overall + 0.2 * goalkeeper_overall);
			break;
		case 4 ://3-5-2
			defence_overall = ( 0.5 * (current_team.fix_players[2].skill + current_team.fix_players[3].skill + current_team.fix_players[4].skill) + 0.3 * (current_team.fix_players[2].form + current_team.fix_players[3].form + current_team.fix_players[4].form) + 0.2 * (current_team.fix_players[2].fitness + current_team.fix_players[3].fitness + current_team.fix_players[4].fitness)) / 3; 
			mid_overall = 0.2 * ( 0.5 * (current_team.fix_players[5].skill + current_team.fix_players[6].skill + current_team.fix_players[7].skill + current_team.fix_players[8].skill + current_team.fix_players[9].skill) + 0.3 * (current_team.fix_players[5].form + current_team.fix_players[6].form + current_team.fix_players[7].form + current_team.fix_players[8].form + current_team.fix_players[9].form) + 0.2 * (current_team.fix_players[5].fitness + current_team.fix_players[6].fitness + current_team.fix_players[7].fitness + current_team.fix_players[8].fitness + current_team.fix_players[9].fitness));
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
			mid1_overall = 0.5 * (0.5 * ( 0.5 * (team1.fix_players[6].skill + team1.fix_players[7].skill) + 0.5 * (team1.fix_players[6].form + team1.fix_players[7].form) + 0.2 * (team1.fix_players[6].fitness + team1.fix_players[7].fitness))) + 0.6 * (0.5 * ( 0.5 * (team1.fix_players[8].skill + team1.fix_players[9].skill) + 0.3 * (team1.fix_players[8].form + team1.fix_players[9].form) + 0.2 * (team1.fix_players[8].fitness + team1.fix_players[9].fitness)));
			break;
		case 2 ://4-3-3
			mid1_overall = ( 0.5 * (team1.fix_players[6].skill + team1.fix_players[7].skill + team1.fix_players[8].skill) + 0.3 * (team1.fix_players[6].form + team1.fix_players[7].form + team1.fix_players[8].form) + 0.2 * (team1.fix_players[6].fitness + team1.fix_players[7].fitness + team1.fix_players[8].fitness)) / 3; 
			break;
		case 3 ://5-4-1
			mid1_overall = 0.5 * (0.5 * ( 0.5 * (team1.fix_players[8].skill + team1.fix_players[7].skill) + 0.3 * (team1.fix_players[8].form + team1.fix_players[7].form) + 0.2 * (team1.fix_players[8].fitness + team1.fix_players[7].fitness))) + 0.5 * (0.5 * ( 0.5 * (team1.fix_players[9].skill + team1.fix_players[10].skill) + 0.3 * (team1.fix_players[10].form + team1.fix_players[9].form) + 0.2 * (team1.fix_players[10].fitness + team1.fix_players[9].fitness)));
			break;
		case 4 ://3-5-2
			mid1_overall = 0.2 * ( 0.5 * (team1.fix_players[5].skill + team1.fix_players[6].skill + team1.fix_players[7].skill + team1.fix_players[8].skill + team1.fix_players[9].skill) + 0.3 * (team1.fix_players[5].form + team1.fix_players[6].form + team1.fix_players[7].form + team1.fix_players[8].form + team1.fix_players[9].form) + 0.2 * (team1.fix_players[5].fitness + team1.fix_players[6].fitness + team1.fix_players[7].fitness + team1.fix_players[8].fitness + team1.fix_players[9].fitness));
			break;	
	}
	switch(team2.formation)
	{
		case 1 ://4-4-2
			mid2_overall = 0.5 * (0.5 * ( 0.5 * (team2.fix_players[6].skill + team2.fix_players[7].skill) + 0.5 * (team2.fix_players[6].form + team2.fix_players[7].form) + 0.2 * (team2.fix_players[6].fitness + team2.fix_players[7].fitness))) + 0.6 * (0.5 * ( 0.5 * (team2.fix_players[8].skill + team2.fix_players[9].skill) + 0.3 * (team2.fix_players[8].form + team2.fix_players[9].form) + 0.2 * (team2.fix_players[8].fitness + team2.fix_players[9].fitness)));
			break;
		case 2 ://4-3-3
			mid2_overall = ( 0.5 * (team2.fix_players[6].skill + team2.fix_players[7].skill + team2.fix_players[8].skill) + 0.3 * (team2.fix_players[6].form + team2.fix_players[7].form + team2.fix_players[8].form) + 0.2 * (team2.fix_players[6].fitness + team2.fix_players[7].fitness + team2.fix_players[8].fitness)) / 3; 
			break;
		case 3 ://5-4-1
			mid2_overall = 0.5 * (0.5 * ( 0.5 * (team2.fix_players[8].skill + team2.fix_players[7].skill) + 0.3 * (team2.fix_players[8].form + team2.fix_players[7].form) + 0.2 * (team2.fix_players[8].fitness + team2.fix_players[7].fitness))) + 0.5 * (0.5 * ( 0.5 * (team2.fix_players[9].skill + team2.fix_players[10].skill) + 0.3 * (team2.fix_players[10].form + team2.fix_players[9].form) + 0.2 * (team2.fix_players[10].fitness + team2.fix_players[9].fitness)));
			break;
		case 4 ://3-5-2
			mid2_overall = 0.2 * ( 0.5 * (team2.fix_players[5].skill + team2.fix_players[6].skill + team2.fix_players[7].skill + team2.fix_players[8].skill + team2.fix_players[9].skill) + 0.3 * (team2.fix_players[5].form + team2.fix_players[6].form + team2.fix_players[7].form + team2.fix_players[8].form + team2.fix_players[9].form) + 0.2 * (team2.fix_players[5].fitness + team2.fix_players[6].fitness + team2.fix_players[7].fitness + team2.fix_players[8].fitness + team2.fix_players[9].fitness));
			break;	
	}
	return (50 - (mid1_overall - mid2_overall) / 2);
}
void matchSim(Team team1,Team team2,char date)
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
	
}
