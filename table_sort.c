void tableSort()
{
	int i,j,int_temp;
	char name_temp[100];
	for (i = 0 ; i < 16 ; i++)
	{
		strcpy(sorted_teams[i].name) = strcpy(teams[i].name);
		sorted_teams[i].win = teams[i].win;
		sorted_teams[i].draw = teams[i].draw;
		sorted_teams[i].lose = teams[i].lose;
		sorted_teams[i].goals_for = teams[i].goals_against
		sorted_teams[i].goals_against = teams[i].goals_against;
		sorted_teams[i].points = teams[i].points;
	}
	for (i = 0 ; i < 16 ; i++)
	{
		for (j = i + 1 ; j < 16 ; j++)
		{
			if(sorted_teams[i].points < sorted_teams[j].points)
			{
					strcpy(name_temp) = strcpy(sorted_teams[i].name);
					strcpy(sorted_teams[i].name) = strcpy(sorted_teams[j].name);
					strcpy(sorted_teams[j].name) = strcpy(name_temp);
					
					int_temp = sorted_teams[i].win;
					sorted_teams[i].win = sorted_teams[j].win;
					sorted_teams[j].win = int_temp;
					
					int_temp = sorted_teams[i].draw;
					sorted_teams[i].draw = sorted_teams[j].draw;
					sorted_teams[j].draw = int_temp;
					
					int_temp = sorted_teams[i].lose;
					sorted_teams[i].lose = sorted_teams[j].lose;
					sorted_teams[j].lose = int_temp;
					
					int_temp = sorted_teams[i].goals_for;
					sorted_teams[i].goals_for = sorted_teams[j].goals_for;
					sorted_teams[j].goals_for = int_temp;
					
					int_temp = sorted_teams[i].goals_against;
					sorted_teams[i].goals_against = sorted_teams[j].goals_against;
					sorted_teams[j].goals_against = int_temp;
					
					int_temp = sorted_teams[i].points;
					sorted_teams[i].points = sorted_teams[j].points;
					sorted_teams[j].points = int_temp;
			}
			if(sorted_teams[i] = sorted_teams[j] && ((sorted_teams[i].goals_for - sorted_teams[i].goals_against) < (sorted_teams[j].goals_for - sorted_teams[j].goals_against))
			{
						strcpy(name_temp) = strcpy(sorted_teams[i].name);
					strcpy(sorted_teams[i].name) = strcpy(sorted_teams[j].name);
					strcpy(sorted_teams[j].name) = strcpy(name_temp);
					
					int_temp = sorted_teams[i].win;
					sorted_teams[i].win = sorted_teams[j].win;
					sorted_teams[j].win = int_temp;
					
					int_temp = sorted_teams[i].draw;
					sorted_teams[i].draw = sorted_teams[j].draw;
					sorted_teams[j].draw = int_temp;
					
					int_temp = sorted_teams[i].lose;
					sorted_teams[i].lose = sorted_teams[j].lose;
					sorted_teams[j].lose = int_temp;
					
					int_temp = sorted_teams[i].goals_for;
					sorted_teams[i].goals_for = sorted_teams[j].goals_for;
					sorted_teams[j].goals_for = int_temp;
					
					int_temp = sorted_teams[i].goals_against;
					sorted_teams[i].goals_against = sorted_teams[j].goals_against;
					sorted_teams[j].goals_against = int_temp;
					
					int_temp = sorted_teams[i].points;
					sorted_teams[i].points = sorted_teams[j].points;
					sorted_teams[j].points = int_temp;
			}
		}
	}
}
