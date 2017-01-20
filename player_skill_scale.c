void skillScale(int j) // M = MID , A = FORWARD , G = GOALKEEPER , D = DEFENCE
{
	if(user.fix_players[j].original_post == 'M' && user.fix_players[j].post == 'A')
		user.fix_players[j].skill = 0.7 * user.fix_players[j].base_skill		
	if(user.fix_players[j].original_post == 'M' && user.fix_players[j].post == 'D')
		user.fix_players[j].skill = 0.4 * user.fix_players[j].base_skill
	if(user.fix_players[j].original_post == 'A' && user.fix_players[j].post == 'M')
		user.fix_players[j].skill = 0.7 * user.fix_players[j].base_skill
	if(user.fix_players[j].original_post == 'A' && user.fix_players[j].post == 'D')
		user.fix_players[j].skill = 0.25 * user.fix_players[j].base_skill
	if(user.fix_players[j].original_post == 'D' && user.fix_players[j].post == 'A')
		user.fix_players[j].skill = 0.25 * user.fix_players[j].base_skill
	if(user.fix_players[j].original_post == 'D' && user.fix_players[j].post == 'M')
		user.fix_players[j].skill = 0.5 * user.fix_players[j].base_skill
}

