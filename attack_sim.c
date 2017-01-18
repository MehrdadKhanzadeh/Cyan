float teamAttack(Team current_team)
{
	float attack_overall ,mid_overall;
	switch(team_name.formation)
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
