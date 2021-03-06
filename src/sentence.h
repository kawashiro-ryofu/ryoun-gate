/*

	Copyright (C)2020 Jeffery_Yu(Kawashiro_Ryofu)
    Licence Under MIT
    
    sentence.h
	这里是整理好的名句
    （虽然没必要整合到头文件里，但目的达成就行）
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* randSentence(){
	char* sentences[]={
    "没必要的事就不做，必要的事就尽快做。——《冰菓》",
    "因为触碰的差别而察觉到真相，应该说是侥幸吧。——《猫物语》",
    "我只会和需要我的人,一起走下去 ——《缘之空》",
    "我觉得你比我幸福，因为你可以选择爱我或不爱我，而我只能选择爱你或更爱你。——《school days》",
    "即使交不到100个朋友也没关系，只要交到比100个朋友更重要的朋友，——《我的朋友很少》",
    "即使忘记了一起生活的伙伴的长相，也不会忘记深刻在灵魂里的羁绊。——《Angel Bests》",
    "美丽的不是这个世界，而是接受这个世界的美丽的，你的眼睛。——《吸血鬼骑士》",
    "一个人才会混乱的吧，即使是在黑暗中，只要有个人和自己一起走的话，就会安心很多，也一定会找到答案的。——《Ture Tears》",
    "重要的，珍惜的，一直在身边，一旦成为理所当然，就难以发现。——K-ON",
    "天空是连着的，如果我们也能各自发光的话，就算距离有多远，都能看到彼此努力的身影。——《龙与虎》",
    "邂逅的，是指向温柔的代价。 坠落的，是通向悲伤的迷宫。 焦虑的 ，是走向憎恨的思绪 。 ——《寒蝉鸣泣之时》",
    "失去了翅膀的鸟儿，是不能在名为记忆的蔚蓝天空上飞翔的。但是，我深信，只要自己活着，回忆就会像流逝的时间一样，会有崭新的诞生 ——《魔卡少女樱》",
    "连自己的生命都可以轻言放弃的人，是没有资格说要保护谁的!——《潘多拉之心》",
    "有被杀的觉悟, 才有资格开枪——《反叛的鲁路修》",
    "命运的红线一旦断了, 就再也不会再接上——《犬夜叉》",
    "曾经发生过的事请不会忘记,只是想不起来而已——《千与千寻》",
    "要活下去，总有一天我们能笑着缅怀过去的艰辛---《不思议游戏》",
    "无法飞翔的翅膀也是有意义的, 因为它是曾经翱翔于天空所留下的珍贵回忆——神尾观铃《AIR》",
    "比任何人都要了解自己, 比任何人都要关爱自己... 喜欢上这样的人, 并没有什么奇怪的呢——《初音岛》",
    "如果你愿意的话... 让我带您去吧... 这座小镇... 愿望实现的地方...——古河渚《Clannad》",
    "人们要是没有回忆就活不下去 但是只有回忆的话也活不下去 梦总是有会醒来的时候 不会醒的梦总有一天会变成悲伤---《AIR》",
    "不能推脱。不能忘记。不能消除。不能蹂躏。不能一笑而过。也不能被美化。什么都不能。只能面对如此真实而残酷，无所作为却仅有一次的人生啊——《Angel Beats》",
    "世界很美，即使充满了悲伤和泪水，请你睁开双眼，去做你想做的事，成为你想成为的人，去爱你想爱的人，找你想要的朋友。不必焦躁，不必迷惘，请慢慢地长大，无论发生什么事情，请不要后悔与这个世界相遇。——《Clannad》",
    "一条路不能回头，就是一生要走许多路，有成长之路。很多事情不能自己掌控，即使再孤单再寂寞，仍要继续走下去，不许停也不能回头。——《千与千寻》",
    "人生就是一列开往坟墓的列车，路途上会有很多站，很难有人可以自始至终陪着走完。当陪你的人要下车时，即使不舍也该心存感激，然后挥手道别。——《千与千寻》",
    "隐约雷鸣，阴霾天空，即使天无雨，我亦留此地，如果下雨了，你愿意留下吗？即使不下雨，我也在这里啊！——《言叶之庭》",
    "以前的事是不会忘记的，只是想不起来了而已。——《千与千寻》",
    "这世上有一条路无论如何也不能走，那就是歧途，只要走错一步结果都会是粉身碎骨。——《千与千寻》",
    "因为遇见你，我才知道我也能拥有美丽的记忆。所以，无论你怎么对待我，我都会用心去宽恕你的恨，用心去铭记你的好。——《千与千寻》",
    "自己的力量无法触及的部分决定着自己的未来。无论自己多么努力，还是有无法改变的地方。——《樱花庄的宠物女孩》",
    "执着于复仇与憎恨，即使美好就在眼前，也会视而不见。——《名侦探柯南》",
    "小心翼翼，屏住呼吸，好怕下一秒这萤火绮丽的梦幻会消失。——《萤火之森》",
    "失去就在一瞬间，一瞬间的疏忽。不管是多么珍惜的东西，在一瞬间就会触碰不到。——《萤火之森》",
    "我希望不论什么时候，你都不要后悔我们的相遇。——古河渚《Clannad》",
    "笑是对身边的事物感到一瞬间的幸福而表现出来的东西。——冈崎朋也《Clannad》",
    "前天遇到了小鹿，昨天是小兔子，今天是你。——一之濑琴美《Clannad》",
    "我们一起迈开了脚步，在这长长的，长长的坡道上。——古河渚《Clannad》",
    "这是一个考验，来自过去的考验，人的成长，就是战胜自己不成熟的过去。——狄阿波罗《JOJO奇妙冒险》",
    "吾心吾行澄如明镜，所作所为皆属正义！——法尼·瓦伦泰《JOJO奇妙冒险》",
    "我认为只有跨越了来自人类自身恐惧的人，才有资格被称为站在颠峰的人。我是这样认为的。——迪奥·布兰度《JOJO奇妙冒险》",
    "人类的赞歌就是勇气的赞歌！——威尔·A·齐贝林 《JOJO奇妙冒险》",
    "JOJO，我不想再做人了！——Dio《JOJO奇妙冒险》",
    "我真是High到不行啊！——Dio《JOJO奇妙冒险》",
    "ロードローラーだッ!——Dio《JOJO奇妙冒险》",
    "奇迹不是免费的，如果你祈求了希望，也会散播出同等的绝望。——佐仓杏子《魔法少女小圆》",
    "谁都无法相信未来，谁都无法接受未来。——晓美焰《魔法少女小圆》",
    "拜托了，神啊，都经过了这样的人生……请让我做一次幸福的梦吧……——佐仓杏子《魔法少女小圆》",
    "已经不用再诅咒任何人，再伤害任何人了。一切因果由我承担，所以拜托了，直到最后，都要相信自己。——鹿目圆《魔法少女小圆》",
    "你并不是实现了希望，而是你自己成为了希望，成为了我们所有人的希望。——巴麻美《魔法少女小圆》",
    "就算是没有魔女诞生的世界，人类世界的诅咒也不会消失，为了改变世界的扭曲和形状，仍有幻影在不断诅咒着人类。——《魔法少女小圆》",
    "所谓正确，就是即使做错也不后悔。——红A《fate/stay night》",
    "他人比自己更重要的这种想法，想让所有人都幸福的愿望，只不过空想中的童话罢了。如果你必须抱着这种东西才能活下去的话，就抱着它溺死吧——Archer《Fate/Stay Night Unlimited Blade Works》",
    "此后吾之剑与汝同在，汝之命运与吾共存。——saber《fate/stay night》",
    "就算我的人生是虚伪的，但希望所以人都幸福的这个愿望也依然是美丽的——卫宫士郎《fate/stay night》",
    "兵器不论真赝，只取决于使用者的能力——红A《fate/stay night》",
    "“转瞬即逝的相逢与离别，每一个瞬间，我都想要珍惜。”——夏目贵志《夏目友人帐》",
    "记忆是一种相聚的方式，放下是一种自由的形式。不必悲伤，不必忧愁，邂逅的回忆都是美好的故事。——《夏目友人帐》",
    "伴随各种邂逅，回忆会永留于心。——《夏目友人帐》",
    "“我是人类的朋友，收揽人类的苦厄，并将其交诸众神。如果你需要的话，我也可以代你承受所有的灾厄哦。”——键山雏《东方Project》",
    "我作为永远的居住者，过去是无限的，所以呢。现在不高兴的话不就没有意义了吗？千年也好万年也好，没有什么比得上现在这一瞬间。即使是一秒，过去的事怎么样都好。——蓬莱山辉夜《东方Project》",
    "随着信息社会的发展想象力灭绝了。当人们都能平等地获得信息时，想象的余地便不存在了。——ZUN",
    "每天光是活着就拼尽全力，有点娱乐就能满足。然后把这种观点代代传承下去的人类，只是粗略地看看标题和照片，就以为自己已经了解了全世界的事情的人类——射命丸文《东方Project》",
    "“ 茶的香味只会因为扩散而变淡，但绝对不会消失。”——西行寺幽幽子《东方Project》",
    "天地之道正所谓，物极必反——比那名居天子《东方Project》",
    "“在这个幻想乡不能被常识所束缚！”——东风谷早苗《东方Project》"
    
    };
	srand(time(0));
	//In = sentences[rand() % 65];
	char* Out = sentences[rand()%65];
	return Out;
}	

	
	
	
	
	
	
	
	
