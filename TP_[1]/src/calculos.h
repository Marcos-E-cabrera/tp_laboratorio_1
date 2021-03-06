#ifndef CALCULOS_C_
#define CALCULOS_C_

/** pido ingresar los kilometros del vuelo
 *
 * @return kilometros del vuelo
 */
float kilometrosDeVuelo();

/** Opcion 3 - A ( descuento 10% )
 *
 * @param importe ingresa el precio de Aerolineas
 * @return descuento de 10%
 */
float descuento(float importe);

/** Opcion 3 - b ( inter?s 25% )
// *
// * @param importe ingresa el precio de Aerolineas
// * @return inter?s 25%
// */
float credito(float importe);

/** Opcion 3 - c ( Bitcoin )
 *
 * @param importe ingresado
 * @return precio en  Bitcoin
 */
float bitcoin(float importe);

/** Opcion 3 - d ( precio unitario )
 *
 * @param kms ingreso los kilometros del vuelo
 * @param importe ingreso precio de Aerolinas o Latam
 * @return precio unitario
 */
float precioUnitario(float importe, float kms);

/** diferencia de precios
 *
 * @param y precio Aerolineas
 * @param z precio Latam
 * @return difrecia de precio
 */
float difPrecio(float y , float z);

/** datos forzados
 *
 * @return todos los datos ingresados internamente
 */
void datosForzados();


#endif /* CALCULOS_C_ */
