// 1. 2차원 그래프(표)를 만들어 주고 받은 선물을 기록
//    graph[준사람][받은사람] = 갯수
// 2. 각자의 선물 지수를 계산
// 3. 두명씩 짝 지어 선물기록 비교

// ! 친구들의 이름을 key 로 하지 않고 이름 -> index 로 맵핑하는 함수를 따로 두었어도 깔끔했을듯!

function solution(friends, gifts)
{

    const graph = {};

    friends.forEach((giver) = > {
        graph[giver] = {};
        friends.forEach((receiver) = > {
            graph[giver][receiver] = 0;
        })
    })

        const gift_level = {}; // 선물 지수

    // 초기화
    friends.forEach((friend) = > {
               gift_level[friend] = 0;
           })

        gifts.forEach((gift) = > {
            const words = gift.split(' ');
            const giver = words[0];
            const receiver = words[1];

            graph[giver][receiver]++;

            gift_level[giver]++;
            gift_level[receiver]--;
        })

            let result = {};

    for (let i = 0; i < friends.length; i++)
    {

        let f1 = friends[i];

        for (let j = i + 1; j < friends.length; j++)
        {

            let f2 = friends[j];

            // 선물 받은 기록 비교
            if (graph[f1][f2] > graph[f2][f1])
            {

                if (result[f1] == undefined)
                {
                    result[f1] = 1;
                }
                else
                {
                    result[f1]++;
                }
            }
            else if (graph[f1][f2] < graph[f2][f1])
            {

                if (result[f2] == undefined)
                {
                    result[f2] = 1;
                }
                else
                {
                    result[f2]++;
                }
            }
            else
            { // 같다면 선물지수 비교

                console.log("선물지수 :", gift_level[f1], gift_level[f2]);
                if (gift_level[f1] < gift_level[f2])
                {
                    if (result[f2] == undefined)
                    {
                        result[f2] = 1;
                    }
                    else
                    {
                        result[f2]++;
                    }
                }
                else if (gift_level[f1] > gift_level[f2])
                {
                    if (result[f1] == undefined)
                    {
                        result[f1] = 1;
                    }
                    else
                    {
                        result[f1]++;
                    }
                }
            }
        }
    }

    let answer = 0;

    for (const key in result)
    {
        console.log(result[key]);
        if (result[key] > answer)
        {
            answer = result[key];
        }
    }

    return answer;
}