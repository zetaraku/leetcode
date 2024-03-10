#!/usr/bin/bash

# update problems.json manually from 'https://leetcode.com/api/problems/all/'

cat ./problems.json | jq '
  [
    .stat_status_pairs[] | {
      no: .stat.frontend_question_id,
      title: .stat.question__title,
      slug: .stat.question__title_slug,
      difficulty: .difficulty.level | (
        if . == 1 then
          "easy"
        elif . == 2 then
          "medium"
        elif . == 3 then
          "hard"
        else
          null
        end
      ),
    }
  ] | sort_by(.no)
'
