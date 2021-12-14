char Azbuka[] = {
  'A', // 'A'
  'B', // 'Б'
  'V', // 'В'
  'G', // 'Г'
  'D', // 'Д'
  ']', // 'Ђ'
  'E', // 'Е'
  '|', // 'Ж'
  'Y', // 'З'
  'I', // 'И'
  'J', // 'Ј'
  'K', // 'К'
  'L', // 'Л'
  'Q', // 'Љ'
  'M', // 'М'
  'N', // 'Н'
  'W', // 'Њ'
  'O', // 'О'
  'P', // 'П'
  'R', // 'Р'
  'S', // 'С'
  'T', // 'Т'
  '"', // 'Ћ'
  'U', // 'У'
  'F', // 'Ф'
  'H', // 'Х'
  'C', // 'Ц'
  ':', // 'Ч'
  'X', // 'Џ'
  '{', // 'Ш'
};


int uzajamnoProsti(int a, int b)  
{  
    int min, br, flag = 1;  
  
    min = a < b ? a : b;  
  
    for(br = 2; br <= min; br++)  
    {  
        if( a % br == 0 && b % br == 0 )  
        {  
            flag = 0;  
            break;  
        }  
    }  
  
    return(flag);  
}


int inverzniModuo(int a, int b)
{
	  int b0 = b, t, q, x0 = 0, x1 = 1;

	  if (b == 1) return 1;

	  while (a > 1) {
		  q = a / b;
		  t = b;
      b = a % b; 
      a = t;
		  t = x0;
      x0 = x1 - q * x0;
      x1 = t;
	  }

	  if (x1 < 0) {
      x1 += b0;
    }

	  return x1;
}


int moduo30(int a)
{
    int r = a % 30;
    return r < 0 ? r + 30 : r;
}