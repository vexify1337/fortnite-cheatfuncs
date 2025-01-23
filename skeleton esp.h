if (visuals.skeleton && visuals.enable && distance <= 50)
		{
			fvector2d bonePositions[17]; // Increased size for 110 index
			const int boneIndices[] = { 67, 3, 66, 9, 38, 10, 39, 11, 40, 78, 71, 79, 72, 75, 82, 67, 110 }; // Added 110 index
			for (int i = 0; i < 17; ++i) // Loop for 17 bones now
			{
				bonePositions[i] = game_helper.ProjectWorldToScreen(game_helper.getsocketlocation(SkeletalMesh, boneIndices[i]));
			}
			
			std::pair<int, int> bonePairs[] =
			{
				{1, 2}, {3, 4}, {4, 3}, {5, 3}, {6, 4}, {5, 7}, {6, 8},
				{10, 1}, {9, 1}, {12, 10}, {11, 9}, {13, 12}, {14, 11}, {2, 15}, {15, 0}
			};

			ImGui::GetBackgroundDrawList()->PushClipRectFullScreen();
			for (const auto& pair : bonePairs)
			{
				ImVec2 start(bonePositions[pair.first].x, bonePositions[pair.first].y);
				ImVec2 end(bonePositions[pair.second].x, bonePositions[pair.second].y);

				if (pair.first == 67)
				{
					end.y += 30;
				}

				if (visuals.skel_outline)
				{
					ImGui::GetBackgroundDrawList()->AddLine(start, end, ImColor(0, 0, 0, 255), visuals.skeleton_thickness + 2);
				}


				ImGui::GetBackgroundDrawList()->AddLine(start, end, box_color, visuals.skeleton_thickness);
			}

			ImGui::GetBackgroundDrawList()->PopClipRect();
		}
